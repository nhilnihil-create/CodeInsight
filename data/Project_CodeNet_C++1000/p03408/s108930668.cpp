#include <bits/stdc++.h>
using namespace std;
#ifdef ENABLE_DEBUG_OUTPUT
#define DEBUG_LOG(s) cout << s << endl;
#else
#define DEBUG_LOG(s) void();
#endif

int main(){
    int n, m; cin >> n;

    map<string, int> s, t;
    set<string> c;
    for (auto i = 0; i < n; i++) {
        string tmp; cin >> tmp; s[tmp]++;
        c.insert(tmp);
    }
    cin >> m;
    for (auto i = 0; i < m; i++) {
        string tmp; cin >> tmp; t[tmp]++;
        c.insert(tmp);
    }

    int ans = 0;
    for (auto & elm : c) ans = max(ans, s[elm] - t[elm]);

    cout << ans << endl;
    return 0;
}
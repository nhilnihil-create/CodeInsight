#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    
    if (s.size() == 1) {
        cout << s << endl;
        return 0;
    }
    int ans = s[0] - '0' - 1 + (s.size() - 1) * 9;
    bool all_nine = true;
    rep(i,s.size()) if (i > 0 && s[i] != '9') all_nine = false;
    if (all_nine) ans++;
    cout << ans << endl;
}
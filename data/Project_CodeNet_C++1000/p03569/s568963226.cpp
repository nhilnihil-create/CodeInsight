#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define int long long
#define double long double
const int INF = 1e18, MOD = 1e9 + 7;

signed main() {
    deque<char> s;
    char c;
    while (cin>>c) {
        s.push_back(c);
    }
    int ans = 0;
    while (s.size() > 1) {
        if (s[0] == s[s.size() - 1]) {
            s.pop_back();
            s.pop_front();
        } else if (s[0] == 'x') {
            s.pop_front();
            ans++;
        } else if (s[s.size() - 1] == 'x') {
            s.pop_back();
            ans++;
        } else {
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
}
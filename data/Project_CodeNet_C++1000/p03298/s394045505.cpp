#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
string s;
map<string,ll> mp[20];

int main() {
    cin >> n >> s;
    string ss;
    ll ans = 0;
    ss = s.substr(0,n);
    for (int i = 0; i < (1 << n); i++) {
        string tmp = "";
        int cnt = 0;
        for (int j = 0; j < n; j++)  {
            if (i & (1 << j)) {
                tmp += ss[j];
                cnt++;
            }
        }
        for (int j = n - 1; j >= 0; j--) {
            if (!(i & (1 << j))) {
                tmp += ss[j];
            }
        }
        mp[cnt][tmp]++;
    }
    ss = s.substr(n,n);
    for (int i = 0; i < (1 << n); i++) {
        string tmp = "";
        int cnt = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (i & (1 << j)) {
                tmp += ss[j];
                cnt++;
            }
        }
        for (int j = 0; j < n; j++)  {
            if (!(i & (1 << j))) {
                tmp += ss[j];
            }
        }
        ans += mp[cnt][tmp];
    }
    cout << ans << endl;
    return 0;
}

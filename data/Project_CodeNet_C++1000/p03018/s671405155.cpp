#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define int long long
#define double long double
const int INF = 1e18, MOD = 1e9 + 7;

signed main() {
    string s;
    vector<int> t;
    cin>>s;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == 'B' && s[i + 1] == 'C') t.push_back(2), i++;
        else if (s[i] == 'A') t.push_back(1);
        else t.push_back(0);
    }
    int cnt = 0;
    int ans = 0;
    for (auto c: t) {
        if (c == 0) cnt = 0;
        if (c == 1) cnt++;
        if (c == 2) ans += cnt;
    }
    cout<<ans<<endl;
}
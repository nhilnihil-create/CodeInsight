/**
*    created: 21.06.2020 23:49:31
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pcnt(bit) __builtin_popcount(bit)
#define mod 1000000007
#define pi acos(-1.0)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> c[n+1];
    rep(i,m) {
        int p, y;
        cin >> p >> y;
        c[p].push_back(make_pair(y,i+1));
    }
    rep2(i,1,n+1) sort(all(c[i]));
    vector<string> num(m+1);
    rep2(i,1,n+1) {
        rep(j,c[i].size()) {
            string s = to_string(1000000000000 + 1000000 * i + j+1);
            num[c[i][j].second] = s.substr(1,12);
        }
    }
    rep2(i,1,m+1) {
        cout << num[i] << endl;;
    }
    return 0;
}
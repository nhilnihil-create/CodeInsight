#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;


int main(){
    int n, m, q; cin >> n >> m >> q;
    vector<vector<int>> map(n+1,vector<int>(n+1,0));
    rep(i,m){
        int l, r; cin >> l >> r;
        map[l][r]++;
    }
    rep(i,n) rep(j,n+1) map[i+1][j] += map[i][j];
    rep(i,n) rep(j,n+1) map[j][i+1] += map[j][i];
    rep(i,q){
        int p, q; cin >> p >> q;
        int ans = map[q][q] - map[q][p-1] - map[p-1][q] + map[p-1][p-1];
        cout << ans << endl;
    }
}
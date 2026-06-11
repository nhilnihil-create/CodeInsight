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
    int n, c; cin >> n >> c;
    vector<vector<int>> d(c,vector<int>(c)); rep(i,c) rep(j,c) cin >> d[i][j];
    vector<int> c0(c,0), c1(c,0), c2(c,0);
    rep(i,n) rep(j,n){
        int cc; cin >> cc; cc--;
        if((i+j)%3 == 0) c0[cc]++;
        else if((i+j)%3 == 1) c1[cc]++;
        else if((i+j)%3 == 2) c2[cc]++;
    }
    ll ans = 100100100100100;
    rep(i,c) rep(j,c) rep(k,c){
        if(i == j || j == k || k == i) continue;
        ll count = 0;
        rep(l,c) count += c0[l]*d[l][i];
        rep(l,c) count += c1[l]*d[l][j];
        rep(l,c) count += c2[l]*d[l][k];
        if(count < ans) ans = count;
    }
    cout << ans << endl;
}
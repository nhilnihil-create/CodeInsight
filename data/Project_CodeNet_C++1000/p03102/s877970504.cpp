#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n,m,c;
    cin >> n >> m >> c;
    vector<int> b(m);
    rep(i,m) cin >> b[i];
    vector<vector<int>> a(n,vector<int>(m));
    rep(i,n) rep(j,m) cin >> a[i][j];
    int ans = 0;
    rep(i,n){
        int total = 0;
        rep(j,m){
            total += a[i][j]*b[j];
        }
        if(total+c > 0) ans++;
    }
    cout << ans << endl;
    return 0;
}
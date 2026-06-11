#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i,n) cin >> v[i];
    vector<int> c(n);
    rep(i,n) cin >> c[i];
    int ans = 0;
    rep(i,n){
        if(v[i]-c[i] > 0) ans += v[i]-c[i];
    }
    cout << ans << endl;
    return 0;
}
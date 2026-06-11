#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    ll n,y;
    cin >> n >> y;
    rep(i,n+1){
        rep(j,n+1){
            int k = n - i - j;
            if(k < 0) continue;
            if(i*10000+j*5000+k*1000 == y){
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " <<  -1 << " " <<  -1 << endl;
    return 0;
}
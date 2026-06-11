#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    ll n; cin >> n;
    vector<ll> x(n), y(n), h(n);
    rep(i,n) cin >> x[i] >> y[i] >> h[i];
    rep(i,101) rep(j,101){
        ll hh = 0;
        bool count = true;
        vector<ll> rex(0), rey(0);
        rep(k,n){
            if(hh == 0 && h[k] > 0){
                hh = h[k]+abs(i-x[k])+abs(j-y[k]);
            }
            else if(hh == 0 && h[k] == 0){
                rex.push_back(x[k]);
                rey.push_back(y[k]);
            }
            else if(h[k] > 0){
                ll nh = h[k]+abs(i-x[k])+abs(j-y[k]);
                if(hh != nh){
                    count = false;
                    break;
                }
            }
            else if(h[k] == 0){
                if(hh > abs(i-x[k])+abs(j-y[k])){
                    count = false;
                    break;
                }
            }
        }
        if(count){
          int s = rex.size();
            rep(k,s){
                if(hh > abs(i-rex[k])+abs(j-rey[k])){
                    count = false;
                    break;
                }
            }
        }
        if(count){
            cout << i << " " << j << " " << hh << endl;
            return 0;
        }
    }
}
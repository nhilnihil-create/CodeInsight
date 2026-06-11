#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (ll i = ll(s); i < ll(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    ll n; cin >> n;
    for(int i=1; i<=3500; i++){
        for(int j=1; j<=3500; j++){
            if((4*i*j - n*i - n*j) != 0 && (n*i*j) % (4*i*j - n*i - n*j) == 0){
                ll ans = (n*i*j)/(4*i*j - n*i - n*j);
              if(ans > 0){
                cout << i << " " <<  j << " " << ans <<endl;
                return 0;
              }
            }
        }
    }
}
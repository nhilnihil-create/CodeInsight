#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    ll ans=0;
    ll i=357;
    while(i<=n){
        bool tj=false,fj=false,sj=false,ej=false;
        ll copy=i;
        if(i%10==3||i%10==5){
            while(copy>0){
                if(copy%10==3){
                    tj=true;
                }
                else if(copy%10==5){
                    fj=true;
                }
                else if(copy%10==7){
                    sj=true;
                }
                else {
                    ej=true;
                    break;
                }
                copy/=10;
            }
            if(tj&&fj&&sj&&(!ej)) ans++;
            if(ej){
                i+=10;
                continue;
            }
            i+=2;
        }
        else if(i%10==7){
            while(copy>0){
                if(copy%10==3){
                    tj=true;
                }
                else if(copy%10==5){
                    fj=true;
                }
                else if(copy%10==7){
                    sj=true;
                }
                else {
                    ej=true;
                    break;
                }
                copy/=10;
            }
            if(tj&&fj&&sj&&(!ej)) ans++;
            i+=16;
        }
    }
    cout << ans << endl;
}
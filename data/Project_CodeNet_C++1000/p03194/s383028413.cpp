#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,p,ans=1;
    cin >> n >> p;
    vector<ll> e(1e6+1);
    ll sp=p;
    for(ll i = 2;i <= 1e6;i ++){
        while(p%i==0){
            e[i] ++;
            p /= i;
        }
    }
    for(ll i = 2;i <= 1e6;i ++){
        if(e[i]>=n) ans *= pow(i,e[i]/n);
    }
    if(n==1&&ans!=sp) ans = sp;
    cout << ans << endl;
    return 0;
}
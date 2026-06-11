#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll GCD(ll a, ll b){ return a ? GCD(b % a, a) : b; }
int main(){
    ll n,m;
    cin>>n>>m;
    ll a=m/n;
    ll b=m%n;
    if(!b) cout<<a<<endl;
    else{
        ll ans=0;
        for(ll i=1; i<(m+n-1)/n; i++){
            if(i*n<=m&&m%i==0){
                ans = max(ans,i);
            }
        }
        cout<<ans<<endl;
    }
}
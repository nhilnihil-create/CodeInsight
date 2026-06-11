#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    ll n;cin >>n;
    vector<ll> h(n);
    ll mx=0,mint=INF;
    bool flg=true;
    ll ans=0;
    for(int i=0;i<n;i++){
        cin >>h[i];
        if(flg&&h[i]<mx){
            flg=false;
            ans+=mx;
            mx=0;
            mint=INF;
        }
        if(!flg&&h[i]>mint){
            flg=true;
            ans-=mint;
            mint=INF;
            mx=0;
        }
        mint=min(mint,h[i]);
        mx=max(mx,h[i]);
    }
    if(n==1||(n>2&&h[n-2]<=h[n-1]))ans+=h[n-1];
    cout << ans << endl;
    return 0;
}


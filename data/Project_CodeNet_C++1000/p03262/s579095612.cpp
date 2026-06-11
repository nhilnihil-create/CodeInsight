#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}


int main(){
    ll N,X; cin>>N>>X;
    vector<ll> x(N);
    for (ll i = 0; i < N; i++){
        cin>>x[i]; //都市の座標
        x[i]=abs(X-x[i]);
    }
    ll ans=gcd(x[0],x[1]);
    for (ll i = 2; i < N; i++){
        ans=gcd(ans,x[i]);
    }
    cout<<ans<<endl;
}

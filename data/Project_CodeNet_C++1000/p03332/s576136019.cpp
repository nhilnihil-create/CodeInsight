#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=2003;
const ll MOD=998244353;

ll rui(ll a,ll b){
    if(b==1) return a%MOD;
    else if(b==0) return 1;
    else if(b%2==0) return (rui(a,b/2)*rui(a,b/2))%MOD;
    else return (rui(a,b-1)*a)%MOD;
}

ll comb(ll a,ll b){
    ll ans=1;
    for(ll i=a;i>a-b;i--){
        ans=ans*i%MOD;
    }
    for(ll i=1;i<=b;i++){
        ans=(ans*rui(i,MOD-2))%MOD;
    }
    return ans;
}

int main(){
    
    ll N,A,B,K;cin>>N>>A>>B>>K;
    ll ans=0;
    vector<ll> X(N+1),Y(N+1);
    X[0]=1;Y[0]=1;
    for(ll i=1;i<=N;i++){
        X[i]=(X[i-1]*i)%MOD;
        Y[i]=rui(X[i],MOD-2)%MOD;
      //cout<<X[i]<<" "<<Y[i]<<endl;
    }
    for(ll i=0;i<=N;i++){
        if((K-i*A)%B!=0) continue;
        ll j=(K-i*A)/B;
        if(j<0||j>N) continue;
        ans+=(X[N]*Y[i]%MOD)*Y[N-i]%MOD*X[N]%MOD*Y[j]%MOD*Y[N-j]%MOD;
        ans=ans%MOD;
    }
    cout<<ans<<endl;
    
}


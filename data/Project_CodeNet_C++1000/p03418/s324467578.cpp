#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const ll BIG=1e15;

int main(){
    int N,K; cin>>N>>K;
    ll ans=0;
    for(int i=K+1;i<=N;i++){
        ll s=N/i;
        ll a=N%i;
        ans+=(s*(i-K));
        if(a>=K) ans+=(a+1-K);
    }
    if(K==0) ans-=N;
    cout<<ans<<endl;
}
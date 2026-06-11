#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll N,K;cin>>N>>K;
    ll ans=0;
    for(ll i=1;i<=N;i++)ans+=(N/i)*max((ll)0,i-K)+max((ll)0,N-N/i*i-K+1);
    if(K==0)ans-=N;
    cout<<ans<<endl;
    return 0;
}
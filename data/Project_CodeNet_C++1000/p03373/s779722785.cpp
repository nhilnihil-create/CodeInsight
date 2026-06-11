#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(ll i=0;i<n;i++)
const ll INF=1e15;
const ll MOD=1000000007;

int main(){
    ll A,B,C,X,Y;cin>>A>>B>>C>>X>>Y;
    ll ans=INF;
    for(ll i=0;i<=2*max(X,Y);i+=2)ans=min(ans,C*i+max((ll)0,X-i/2)*A+max((ll)0,Y-i/2)*B);
    cout<<ans<<endl;
    return 0;
}
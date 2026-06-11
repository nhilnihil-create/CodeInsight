#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    ll n,k,A[200001],B[200001];
    cin>>n>>k;
    rep(i,n) cin>>A[i]>>B[i];
    ll ans=0;
    rep(i,n) if((k|A[i])==k) ans+=B[i];
    rep(i,log2(k)+1){
        if(!(k&(1<<i))) continue;
        ll m=k,a=0;
        m&=~(1<<i);
        for(int j=i-1;j>=0;j--) m|=(1<<j);
        rep(i,n) if((m|A[i])==m) a+=B[i];
        ans=max(ans,a);
    }
    cout<<ans<<"\n";
}
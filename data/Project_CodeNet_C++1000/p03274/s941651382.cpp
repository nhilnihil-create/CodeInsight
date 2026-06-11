#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll =long long;
using namespace std;
using graph=vector<vector<int>>;
using field=vector<string>;
using p =pair<int,int>;
const ll mod=1000000007;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll> x(n);
    for(ll i=0;i<n;++i)cin>>x[i];
    ll ans=10e9;
    rep(i,n-k+1){
        ll tmp1=abs(x[i+k-1]-x[i]);
        ll tmp2=min(tmp1+abs(x[i+k-1]),tmp1+abs(x[i]));
        ans=min(tmp2,ans);
    }
    cout<<ans<<endl;

}
    
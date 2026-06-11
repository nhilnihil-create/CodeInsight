//om nama sivaya
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define INF 9223372036854777ll
#define pb push_back
using namespace std;

void solve(){
    ll n;
    cin>>n;
    int base=1;
    while(base<=n)base*=2;
    vector<ll> tree(2*base);
    vector<ll> hei(n),bea(n);
    for(int i=0;i<n;i++)
    cin>>hei[i];
    for(int i=0;i<n;i++)
    cin>>bea[i];
    vector<ll> dp(n+1);
    for(int flo=0;flo<n;flo++){
        //max in interval 0 to h[flo]
        int x=hei[flo]+base;
        ll bes=0;
        while(x>1){
            if(x&1)
            bes=max(bes,tree[x-1]);
            x/=2;
        }
        dp[hei[flo]]=bes+bea[flo];
        for(int i=base+hei[flo];i>=1;i/=2)
        tree[i]=max(tree[i],dp[hei[flo]]);
        
    }
    ll res=0;
    for(int i=0;i<=n;i++)
    res=max(res,dp[i]);
    cout<<res;
    
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt=1;
    //cin>>tt;
    while(tt--){
        solve();
    }
}

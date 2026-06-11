#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    ll n,x;
    cin>>n>>x;
    vector<ll>a(n);
    ll ans=0;
    rep(0,i,n)cin>>a[i];
    sort(a.begin(),a.end());
    rep(0,i,n){
        if(x>=a[i]){
            if(i==n-1){
                if(a[i]==x)++ans;
            }else{
                x-=a[i];
                ++ans;
            }
        }
    }
    cout<<ans;
}

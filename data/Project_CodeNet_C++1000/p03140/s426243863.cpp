#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a7=1000000007;
ll inf=1000000000000000;
#define rep(i,l,r) for(ll i=l;i<=r;i++)

ll min(ll a,ll b){
    if(a<b)return a;
    return b;
}
ll max(ll a,ll b){
    if(a>b)return a;
    return b;
}

int main(){
    string a,b,c;
    ll n;cin>>n;
    cin>>a>>b>>c;
    ll ans=0;
    ll coun;
    rep(i,0,n-1){
        coun=0;
        if(a[i]==b[i]){
            coun++;
        }
        if(c[i]==b[i]){
            coun++;
        }
        if(a[i]==c[i]){
            coun++;
        }
        if(coun==3){
            ans+=0;
        }else{
            ans+=(2-coun);
        }
        
    }
    cout<<ans<<endl;
    return 0;
}

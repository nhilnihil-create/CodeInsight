#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main (){
    ios_base::sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        ll a,b,ans=0;cin>>a>>b;
        if(a==b) ans=2*a-2;
        else {
            ll tmp=sqrt(a*b);
            if(tmp*tmp==a*b) tmp--;
            if(tmp*(tmp+1)>=a*b) ans=2*tmp-2;
            else ans=2*tmp-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}

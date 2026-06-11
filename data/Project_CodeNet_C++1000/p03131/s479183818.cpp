#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int k,a,b;
    cin>>k>>a>>b;
    if(b-a<=2||k<=a){cout<<1+k<<endl;}
    else{
        ll ans=0;
        ans+=a;
        ll x=k-a+1;
        if(x%2!=0)ans++;
        x/=2;
        ans+=(b-a)*x;
        cout<<ans<<endl;
    }
}

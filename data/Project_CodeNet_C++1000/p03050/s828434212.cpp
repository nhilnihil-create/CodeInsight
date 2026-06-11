#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ll n,a,b,ans=0;cin>>n;
    ll m=sqrt(n);
    
    for(ll i=1;i<=m;++i){
        if(n%i==0){
            a=i-1;
            b=n/i-1;
//            if(a>1 && n%a!=0)ans+=a;
            if(b>1 && n%b!=0 && b!=a)ans+=b;
        }
    }
    cout<<ans<<endl;
	return 0;
}
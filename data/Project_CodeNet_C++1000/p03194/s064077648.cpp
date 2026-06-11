#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
#define M 1000000007

ll power(ll a,ll n){
    ll ans=1;
    while(0<n){
        if(n%2==0){
            a*=a;
            n>>=1;
        }else{
            ans*=a;
            n--;
        }
    }
    return ans;
}

int main(void){
	ll n,p,ans=1;cin>>n>>p;
	if(n==1){cout<<p<<endl;return 0;}
    if(n>=40){cout<<1<<endl;return 0;}
	
	for(int i=2;power(i,n)<=p;i++){
	    while(p%power(i,n)==0){
	        ans*=i;
	        p/=power(i,n);
	    }
	}
	cout<<ans<<endl;
	
	return 0;
}

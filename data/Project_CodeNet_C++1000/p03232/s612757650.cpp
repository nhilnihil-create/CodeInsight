#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll MOD=1000000007;
const ll INF=1000000000;
const ll LINF=4000000000000000010;
ll n;
ll a[100010],s[100010];
ll f[2000010],fi[2000010];
ll mod_pow(ll x,ll n,ll mod){
    ll ret=1;
    while(n>0){
        if(n&1){
            ret=ret*x%mod;
        }
        x=x*x%mod;
        n>>=1;
    }
    return ret;
}

void fact(ll n){
	f[0]=1;
	for(ll i=1;i<=n;i++){
		f[i]=f[i-1]*i%MOD;
	}
	fi[n]=mod_pow(f[n],MOD-2,MOD);
	for(ll i=n-1;i>=0;i--){		
		fi[i]=fi[i+1]*(i+1)%MOD;
	}
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    fact(n);
    ll sum=0;
    for(int i=0;i<n;i++){
        s[i]=f[n]*mod_pow(i+1,MOD-2,MOD);
        s[i]%=MOD;
        sum+=s[i];
        sum%=MOD;
    }
    int id=1;
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=a[i]*sum;
        ans%=MOD;
        sum+=s[id];
        sum+=MOD-s[n-id];
        sum%=MOD;
        id++;
    }
    cout<<ans<<endl;
}	

#include<iostream>
#include<numeric>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<climits>
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define mkp make_pair
#define pll pair<ll,ll>
#define rep(i,from,to) for(int i=from;i<to;i++)
#define repd(i,from,till) for(int i=from;i>=till;i--)
#define waste ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define inf 1e9+1
#define mod 1e9+7
#define inf1 1e18+1
#define pie 3.14159265358979323846
#define N 100005
using namespace std;
/*
ll bin(ll i,ll j){
	ll mid=(i+j)/2;
	if(a[mid]==x)reutrn mid;
	else if(ans>x)return bin(i,mid-1);
	else return bin(mid+1,j);
}/*
ll power(ll base,ll power){
    ll res=1;
    base=base%mod;
    while(power>0){
    	if(power&1){
    		res=(res*base)%mod;
		}
		power=power>>1;
		base=(base*base)%mod;
	}
	return res;
}
*/
/*
int nCr(int x, int y){
	if(y>x)return 0;
	int num=fact[x];
	num*=invfact[y];
	num%=mod;
	num*=invfact[x-y];
	num%=mod;
	return num;
}
*/
/*bool prime[n+1];
void SieveOfEratosthenes(int n){
	rep(i,0,n+1)prime[i]=true
    for (int p=2;p*p<=n;p++)
        if (prime[p])
            for (int i=p*p;i<=n;i+=p)prime[i]=false;
}*/
/*
int gcd(int a,int b){
	if(b==0)return a;
	else return gcd(b,a%b);
}
*/
int solve(){
    ll r,d,x;
    cin>>r>>d>>x;    
	rep(i,0,10){
		ll val=r*x-d;
		x=val;
		cout<<val<<endl;
	}
	return 0;
}
int main(){
    waste;
    int t;
    //cin>>t;
    t=1;
    while(t--){
       	solve();
    }
}

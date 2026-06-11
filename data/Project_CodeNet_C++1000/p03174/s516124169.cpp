#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("-ffloat-store") // to restrict undesirable precision
#pragma GCC optimize ("-fno-defer-pop")// to pop argument of function as soon as it returns
#define all(a) a.begin(),a.end()
#define ll long long int
#define ld long double
ll power(ll a,ll b,ll m){ if(b==0) return 1; if(b==1) return a%m; ll t=power(a,b/2,m)%m; t=(t*t)%m; if(b&1) t=((t%m)*(a%m))%m; return t;}
ll modInverse(ll a, ll m) { return power(a, m-2, m); }
#define ps push_back
#define fs first
#define sc second
#define takeline cin.ignore();
#define iactive cout.flush();
#define N 3000005
#define endl "\n"
#define mod 1000000007
#define PI 3.141592653589793
//((1.0l)*BIG MULTIPLY MAGIC?)
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();
//-----------------------------------------------
ll n; ll ar[21][21]; ll dp[22][(1ll<<21)+1];
ll maxval(ll i,ll mask){
	if(i==n) return 1;
	if(dp[i][mask]!=-1) return dp[i][mask];
	ll j,an=0;
	for(j=0;j<n;j++){
		if(ar[i][j]==1&&((1ll<<j)&mask)==0){
			an=(an+maxval(i+1,((1ll<<j)|mask))%mod)%mod;
		}
	}
	return dp[i][mask]=an%mod;
}
int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll i,j,k,l;
	cin>>n;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>ar[i][j];
		}
	}	
	memset(dp,-1,sizeof(dp));
	ll an=maxval(0,0);
	cout<<an;
	return 0;	
}
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
#define N 100005
#define endl "\n"
#define mod 1000000007
#define PI 3.141592653589793
//((1.0l)*BIG MULTIPLY MAGIC?)
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();
//-----------------------------------------------
ll n,ar[N][2],dp[N][3]; vector<ll> vc[N];
ll maxval(ll i,ll cl,ll p){
	// cout<<i<<" "<<p<<" "<<cl<<endl;
	if(dp[i][cl]!=-1){
		return dp[i][cl];
	}
	ll an=1,fl=0;
	if(cl==1){
		ll a=1,b=1;
		for(auto it:vc[i]){
			if(it==p) continue;
			a=(a*maxval(it,1,i))%mod;
		}
		for(auto it:vc[i]){
			if(it==p) continue;
			b=(b*maxval(it,2,i))%mod;
		}
		return dp[i][cl]=(a+b)%mod;
	}
	else{
		ll a=1;
		for(auto it:vc[i]){
			if(it==p) continue;
			a=(a*maxval(it,1,i))%mod;
		}
		return dp[i][cl]=a;
	}
}
int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll i,j,k,l;
	cin>>n;
	for(i=1;i<n;i++){
		cin>>ar[i][0]>>ar[i][1];
		vc[ar[i][0]].ps(ar[i][1]);
		vc[ar[i][1]].ps(ar[i][0]);
	}
	memset(dp,-1,sizeof(dp));
	ll an=maxval(1,1,0);
	cout<<an;
	return 0;	
}
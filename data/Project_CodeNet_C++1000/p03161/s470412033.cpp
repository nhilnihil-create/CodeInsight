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
//((1.0l)*BIG MULTIPLY MAGIC?)
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();
//-----------------------------------------------
ll n,ar[N],dp[N],k;
ll maxval(ll i){
	if(i>=n) return 0;
	
	if(dp[i]!=-1){
		return dp[i];
	}
	ll an=1e18,j;
	for(j=i+1;j<=i+k&&j<=n;j++){
		an=min(an,maxval(j)+abs(ar[j]-ar[i]));
	}
	return dp[i]=an;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll i,j,l;
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>ar[i];
	}
	memset(dp,-1,sizeof(dp));
	ll an=maxval(1);
	cout<<an;
	return 0;
}
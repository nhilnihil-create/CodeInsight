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
#define takeline cin.ignore();
#define sc second
#define N 3000005
#define endl "\n"
#define mod 1000000007
//((1.0l)*BIG MULTIPLY MAGIC?)
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();
//-----------------------------------------------
ll n; vector<pair<ll,pair<ll,ll>>> vc;
bool comp(const pair<ll,pair<ll,ll>>&a,const pair<ll,pair<ll,ll>>&b){
	return (a.fs+a.sc.fs)<(b.fs+b.sc.fs);
} 
ll dp[1005][20005];
ll maxval(ll i,ll wt){
	if(i==n) return 0;

	if(dp[i][wt]!=-1){
		return dp[i][wt];
	}
	ll an=maxval(i+1,wt);
	if(vc[i].sc.fs>=wt){
		an=max(an,maxval(i+1,wt+vc[i].fs)+vc[i].sc.sc);
	}
	return dp[i][wt]=an;
}
int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll i,j,k,l;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	ll a,b,c;
	for(i=1;i<=n;i++){
		cin>>a>>b>>c;
		vc.ps({a,{b,c}});
	}
	sort(all(vc),comp);

	ll an=maxval(0,0);
	cout<<an;
	return 0;
}
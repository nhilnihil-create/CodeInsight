#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
#define fo(i,s,e_ex) for(i=s;i<e_ex;i++)
#define Fo(i,k,n) for(i=k;k<n?i<=n:i>=n;k<n?i+=1:i-=1)
#define endl '\n'
#define MOD 1000000007//998244353
#define pbb push_back
#define mpp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define mset(arr,val) memset(arr,val,sizeof(arr))
ll n;
double dp[305][305][305];
double answer(ll n1,ll n2,ll n3){
	if(n1+n2+n3==0) return 0;
	if(dp[n1][n2][n3]>=0) return dp[n1][n2][n3];
	double p0,p1,p2,p3,ans=1;
	p0=((double)(n-n1-n2-n3))/n;
	p1=((double)n1)/(n);
	p2=((double)n2)/(n);
	p3=((double)n3)/(n);
	if(n1>0) ans+=p1*answer(n1-1,n2,n3);
	if(n2>0) ans+=p2*answer(n1+1,n2-1,n3);
	if(n3>0) ans+=p3*answer(n1,n2+1,n3-1);
	ans/=(1-p0);
	return dp[n1][n2][n3]=ans;
}
void solve(ll caseno){
	ll i,j,n1=0,n2=0,n3=0,n0=0;
	cin>>n;
	fo(i,0,n){
		cin>>j;
		if(j==1) n1++;
		else if(j==2) n2++;
		else if(j==3) n3++;
	}
	mset(dp,-1);
	double ans=answer(n1,n2,n3);
	cout<<fixed<<setprecision(12)<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t=1;
	//cin>>t;
	for(ll i=1;i<=t;i++){
		solve(i);
	}
	return 0;
}

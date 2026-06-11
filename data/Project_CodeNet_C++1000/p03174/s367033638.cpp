#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vl vector<long long int>
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vb vector<bool>
#define vvl vector<vector<ll> >
#define vvi vector<vector<int> >
#define pl pair<ll,ll>
#define pb push_back
#define PI 3.14159265
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fri(s,n) for(int i=s;i<n;i++)
#define frj(s,n) for(int j=s;j<n;j++)
#define T(i) int i=1;cin>>i;while(i--)
#define vsi vector<set<int> >
#define pii pair<int,int>
#define inf 1e9
#define vpii vector<pair<int,int> >


ll power(ll a,ll b){
    if(b==0)
        return 1;
    if(b&1)
        return a*power(a,b-1);
    ll temp=power(a,b/2);
    return temp*temp;
    }
bool mycompare(ll a,ll b){
    return a>b;
    }
int dp[22][(1<<22)];
int n;
int solve(vvi &relation,int wset,int men){
	if(men==n+1){
      if(wset==0)
        return 1;
      return 0;}
  	if(dp[men][wset]!=-1)
      	return dp[men][wset];
  	int ans=0;
  	for(int w=0;w<n;w++){
    	bool present=(1<<w)&wset;
      	if(present && relation[men][w+1]==1){
          ans+=solve(relation,wset^(1<<w),men+1);
          ans%=mod;
    }}
     return dp[men][wset]=ans;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n;
    vvi relation(n+1,vi(n+1));
  	memset(dp,-1,sizeof dp);
  	for(int i=1;i<=n;i++){
      	for(int j=1;j<=n;j++){
          	cin>>relation[i][j];}}
  	cout<<solve(relation,(1<<n)-1,1);



}

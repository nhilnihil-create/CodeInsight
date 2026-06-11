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
ll dp[101][100005];
int solve(vi& a,int i,int n,int k){
    if(i==n-1){
        if(k<=a[i])
            return 1;
        return 0;}
    if(dp[i][k]!=-1)
        return dp[i][k];
    int ans=0;
    for(int put=0;put<=a[i];put++){
        ans=(ans+solve(a,i+1,n,k-put))%mod;
    }
    //cout<<i<<" "<<ans<<"\n";
    return dp[i][k]=ans%mod;
    }
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	int n,k;
  	cin>>n>>k;
  	vector<int> a(n+1);
  	for(int i=1;i<=n;i++)
      	cin>>a[i];
  	int dp[n+1][k+1];
  	memset(dp,0,sizeof dp);
  	for(int c=0;c<=k;c++)
      dp[1][c]=(c<=a[1]?1:0);
  	for(int i=2;i<=n;i++){
      	dp[i][0]=1;
    	for(int c=1;c<=k;c++){
        	dp[i][c]=((dp[i][c-1] +dp[i-1][c])%mod-((c-1-a[i])>=0?dp[i-1][c-1-a[i]]:0)%mod+mod)%mod;
        }
    }
  	cout<<dp[n][k];

}

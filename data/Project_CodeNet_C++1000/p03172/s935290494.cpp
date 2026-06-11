#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define ppb         pop_back
#define mii         map<ll int,ll int>
#define msi         map<string,ll int>
#define mis         map<ll int, string>
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define mpi         map<pair<ll int,ll int>,ll int>
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define vii         vector<pair<ll int, ll int>>
#define vs          vector<string>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
//#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
// cerr<<1.0/CLOCKS_PER_SEC<<endl;
using namespace std;
#define N  1000000007 
#define MAXN   200005
//ll int dp[1001][100005];
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
cout.precision(15);
ll int n,k;
cin>>n>>k;
vi a(n);
rep(i,0,n)
cin>>a[i];
ll int dp[n+1][k+1];
rep(i,0,n+1)
{
rep(j,0,k+1)
{
if(i==0 && j==0)
{dp[i][j]=1;}
else if(j==0)
{dp[i][j]=1;}
else if(i==0)
{dp[i][j]=0;}
else
{
dp[i][j]=dp[i][j-1]+dp[i-1][j];
if(j>a[i-1])
dp[i][j]-=dp[i-1][j-a[i-1]-1];
dp[i][j]=(dp[i][j]+N)%N;
}}}
cout<<dp[n][k];
 
}
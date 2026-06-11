#include <bits/stdc++.h>
   
using namespace std;
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define vll vector<long long>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define deb(x) cout << #x << "=" << x << endl
#define F(i,a,b) for(ll i=a;i<=b;i++)
#define RF(i,a,b) for(ll i=a;i>=b;i--)
#define in(a,n) F(i,0,n-1)cin>>a[i]
#define vi vector<int>
#define out(a,n) F(i,0,n-1)cout<<a[i]<<" ";cout<<endl
#define mod 1000000007
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define int long long

const int N=405;
const int INF=1e18L+5;
int dp[N][N];
int a[N];
int pre[N];
int n;


int solve(int l,int r)
{
    if(l>r)return 0;
    if(l==r)return 0;
   
    
    int &ans=dp[l][r];
    if(ans!=-1)return ans;
    ans=INF;
    for(int i=l;i<=r-1;i++)
    {
        ans=min(ans,solve(l,i)+solve(i+1,r)+pre[r]-pre[l-1]);
    }
    return ans;
}








void solve()
{
    cin>>n;
    memset(dp,-1,sizeof dp);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
    //cout<<'\n';
    int ans=solve(1,n);
    
    cout<<ans<<'\n';
    
    
   
    
   
}

int32_t main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    
	int t=1;
	//cin>>t;
	while(t--)solve();
	    
   
}

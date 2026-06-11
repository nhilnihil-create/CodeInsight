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
const int N=(int)1e5+5,INF=(int)1e18+7;

int n,m;
int dp[N][2];
int a[101];
int solve(int piles,int turn)
{
    
    int f=0;
    
    int &ans=dp[piles][turn];
    if(ans!=-1)return ans;
    ans=-1;
    
    for(int i=1;i<=n;i++)
    {
        if(piles-a[i]>=0){
            
            
        int t=solve(piles-a[i],!turn);
        
        if(turn==0)
        {
            if(ans==-1)ans=t;
            else
            {
                if(ans==1)ans=t;
            }
        }
        else
        {
            if(ans==-1)ans=t;
            else
            {
                if(ans==0)ans=t;
            }
        }
        
        f=1;
        }
    }
    
    if(!f)
    return !turn;
    
    
    return ans;
    
    
    
    
}


void solve()
{
    memset(dp,-1,sizeof dp);
    int k;
    cin>>n>>k;
    
    for(int i=1;i<=n;i++)cin>>a[i];
    
    
    int ans=solve(k,1);
   
    if(ans)
    {
        cout<<"First\n";
    }
    else cout<<"Second\n";
}

int32_t main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    
	int t=1;
	//cin>>t;
	while(t--)solve();
	    
   
}

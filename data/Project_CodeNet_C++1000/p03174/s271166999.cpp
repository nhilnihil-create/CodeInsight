#include <bits/stdc++.h>

using namespace std;
#define int long long int
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define vi vector <int>
#define sz(s) (int)s.size()
#define pii pair<int,int>
#define piii pair< int,pair<int,int> >
#define tiii tuple <int,int,int>
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define rall(v) v.rbegin(),v.rend()
#define endl '\n'
#define matrix vector <vector <int> >
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define NAYAN freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define N 21
#define mod 1000000007
#define mod2 998244353
#define inf 1e18

int dp[(1ll<<N)][N];
int a[N][N];
int n;

int solve(int mask,int j)
{
   // int n_bits=__builtin_popcount(mask);
    if(j==n)
        return 1;

    int &ans=dp[mask][j];

    if(ans!=-1)
        return ans;
    ans=0;

    for(int i=0;i<n;i++)
    {
        if(a[i][j]==1 && !(mask & (1ll<<i)))
        {
            //cout << mask << " " << i << " " << j << endl;
            ans=(ans+solve(mask|(1ll<<i),j+1))%mod;
        }
    }

    return ans;

}


int32_t main()
{
    boost
    // #ifndef ONLINE_JUDGE 
    // NAYAN
    // #endif

    
    cin >> n;
    
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin >> a[i][j];
        }
    }

    memset(dp,-1,sizeof dp);

    int ans=solve(0,0);
    cout << ans;
    
    
    
}
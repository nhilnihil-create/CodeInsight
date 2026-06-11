#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(v) v.begin(), v.end()
#define vl vector<ll>
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second
const int N=100005;
ld dp[3000][3000]={},h[3000]{};
void solve()
{
    int n,k=1,m=0,i=1,j,x,y,l,r,p,q,z;
    ld ans=0;
    cin>>n;
    for(i=1;i<=n;i++) cin>> h[i];
    dp[0][0]=1;
    for(i=1;i<=n;i++)
    {
        for(int heads=0;heads<=i;heads++)
        {
            if(heads)
            dp[i][heads]=dp[i-1][heads-1]*h[i];
            dp[i][heads]+=dp[i-1][heads]*(1-h[i]);
        }
    }
    for(i=(n+1)/2;i<=n;i++)
    ans+=dp[n][i];
    cout<<fixed<<setprecision(15)<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
     #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif 
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}
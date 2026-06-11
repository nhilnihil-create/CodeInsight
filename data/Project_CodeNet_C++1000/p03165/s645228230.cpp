#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(NULL); 
#define fi first
#define se second
#define mp make_pair
#define pi 3.14159265359
#define MOD 1000000007
#define inf 1e18
#define setbits(x) __builtin_popcountll(x)
typedef long long ll;
#define mp make_pair
#define ALL(v) v.begin(), v.end() 
#define F(i,s,n) for(i=s;i<n;++i)
#define pb push_back
#define eb emplace_back
#define tin freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define pll pair<ll,ll>
ll max(ll a,ll b)
{
    return a*(a>=b)+b*(b>a);
}
string smax(string a,string b)
{
    if(a.size()>b.size())return a;
    return b;
}
/*----------------------------------------------------------*/
string a,b;

void solve()
{
    cin>>a>>b;
    ll n=a.size(),m=b.size();
    ll dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(ll i=1;i<n+1;++i)
    {
        for(ll j=1;j<m+1;++j)
        {
            if(a[i-1]==b[j-1])dp[i][j]=1+dp[i-1][j-1];
            dp[i][j]=max(dp[i][j],dp[i][j-1]);
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            //cout<<dp[i][j]<<" ";
        }//cout<<endl;
    }
    ll i=n,j=m;
    string s=" ";
    while(i!=0&&j!=0)
    {
        if(dp[i][j]==dp[i][j-1])--j;
        else if(dp[i][j]==dp[i-1][j])--i;
        else {--i;--j;s=a[i]+s;}
    }cout<<s;
}

int main()
{
    //tin
    fast
    ll tc=1;//cin>>tc;
   for(ll i=1;i<=tc;++i)
   {
    //cout<<"Case #"<<i<<": ";
    solve();
    if(i!=tc)cout<<"\n";
   }
return 0;
}
//End-Cases 
//Precomputation
//Segmentation Fault
//Complexity
//Break it up
//Sub Problems

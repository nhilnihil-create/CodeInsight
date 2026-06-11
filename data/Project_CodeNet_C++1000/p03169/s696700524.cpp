#include<bits/stdc++.h>
#define ll long long 
#define ld long double 
#define rep(i,a,b) for(ll i=a; i<b; ++i)
#define BOOST std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define all(v) v.begin(),v.end()
#define sl(a) a.size()
#define mod 1000000007 
#define lcm(a,b) (a*b)/__gcd(a,b)
#define MAX 10000003
using namespace std;
vector<vector<vector<ld>>> dp(310,vector<vector<ld>>(310,vector<ld>(310,-1)));
ld count(ll n,ll a,ll b,ll c)
{
    if(a+b+c==0) return 0.00;
    if(dp[a][b][c]!=-1) return dp[a][b][c];
    ld k=a+b+c;
    ld sum=n/k;
    if(a) sum+=(a/k)*count(n,a-1,b,c);
    if(b) sum+=(b/k)*count(n,a+1,b-1,c);
    if(c) sum+=(c/k)*count(n,a,b+1,c-1);
    return dp[a][b][c]=sum;
}
void solve()
{
    ll n;  cin>>n;
    ll a=0,b=0,c=0,x;
    rep(i,0,n)
    {
        cin>>x;
        if(x==1) a++;
        else if(x==2) b++;
        else if(x==3) c++;
    }
    cout<<fixed<<setprecision(12)<<count(n,a,b,c);
}
int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
    #endif
    BOOST
    int T=1;  //cin>>T;
    while(T--) solve();
    return 0;
}

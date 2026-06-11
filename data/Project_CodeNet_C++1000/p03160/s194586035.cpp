#include<bits/stdc++.h>
#define fr(i,a,n) for(ll i=a;i<n;i++)
#define YES cout<<"YES"<<endl
#define all(v) v.begin(),v.end()
#define NO cout<<"NO"<<endl
#define pb(x) emplace_back(x)
#define fastio std::ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define vi vector<ll>
#define mi map<ll,ll>
#define pi pair<ll,ll>
#define what(x) cout<<#x<<" ="<<x<<endl;
#define scn(n) scanf("%d",&n)
#define print(a) printf("%d",a);
using namespace std;
using ll =int;
ll n;

ll dp[200005],a[200005]={1000000000};
ll invalid=1e9;
ll cnt=0;
int solve(ll i,ll p)
{ //cnt++;
    if(i==n-1)return dp[i]=0;
    if(i>=n)return 1e9;
    if(dp[i]!=-1)return dp[i];
    //what(p-a[i]);
    //cout<<i<<" GG "<<i+1<<endl;

    ll x=abs(a[i+1]-a[i])+solve( i+1,a[i]);

   // what(x);

    ll y=abs(a[i+2]-a[i])+solve(i+2,a[i]);
   // cout<<i<<" "<<i+2<<endl;
   //what(x); what(y);
    x=min(x,y);



    return dp[i]=x;

}

int main()
{
    ll t;
    memset(dp,-1,sizeof dp);

    scn(n);
    fr(i,0,n)cin>>a[i];

    solve(0,a[0]);

    printf("%d\n",dp[0]);
    //what(cnt);
    //fr(i,0,n)cout<<dp[i]<<" ";

}


























#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define ll             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<ll,ll>
#define vi              vector<ll>
#define mii             map<ll,ll>
#define pqb             priority_queue<ll>
#define pqs             priority_queue<ll,vi,greater<ll> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            ll x; cin>>x; while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct activity{
ll A,B,C;};

ll solve(ll n,vector<activity>v){
    ll dp[n+1][3];
dp[1][0]=v[1].A;
dp[1][1]=v[1].B;
dp[1][2]=v[1].C;
for(int i=2;i<=n;i++)
{
    dp[i][0]=v[i].A+max(dp[i-1][1],dp[i-1][2]);
    dp[i][1]=v[i].B+max(dp[i-1][0],dp[i-1][2]);
    dp[i][2]=v[i].C+max(dp[i-1][1],dp[i-1][0]);
}

return max(dp[n][0],max(dp[n][1],dp[n][2]));

}

int main()
{
    FIO;
    ll a,b,c,d,e,f=0,sum=0,ans,ck=0,m,n,k,p,q,r,t,add=0,x,y,z;

    string s;

    cin>>n;
    vector<activity>v(n+1);
    for(int i=1;i<=n;i++){cin>>v[i].A;cin>>v[i].B;cin>>v[i].C;}
    ans=solve(n,v);
    cout<<ans<<endl;



    return 0;
}
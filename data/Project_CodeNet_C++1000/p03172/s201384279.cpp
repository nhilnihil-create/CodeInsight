#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ll          long long
#define pb          push_back
#define INF         9223372036854775807
#define    endl        '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define lower(u)    transform(u.begin(), u.end(), u.begin(), ::tolower);//convert string u to lowercase;
#define upper(u)    transform(u.begin(), u.end(), u.begin(), ::toupper);
using namespace std;

using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define N  100005

ll n,k;
ll dp[101][N];
ll a[101];

ll dps(ll i,ll l,ll r)
{
    ll x=0,y=0;
    if(l!=-1)
    {
        x=dp[i][l];
    }
    y=dp[i][r];
    return (y-x+hell)%hell;
}
void solve()
{
    cin>>n>>k;
    rep(i,1,n+1)
    {
        cin>>a[i];
    }
    rep(i,0,k+1)
        dp[0][i]=1;
    rep(i,1,n+1)
    {
        dp[i][0]=1;
        rep(j,1,k+1)
        {
            dp[i][j]=(dp[i][j-1]+dps(i-1,j-min(j,a[i])-1,j))%hell;
        }
    }
    cout<<dps(n,k-1,k)<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int TESTS=1;
//    cin>>TESTS;
    while(TESTS--)
    {
        solve();
    }
    return 0;
}
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
#define N  305
double dp[N][N][N];
ll n,x;
double m,A,B,C,D;
ll a[4];
double dps(ll a,ll b,ll c)
{
    // cout<<a<<" "<<b<<" "<<c<<endl;
    if(a<0||b<0||c<0)
        return 0;
    if(a==0&&b==0&&c==0)
        return 0;
    ll sum=a+b+c;
    if(dp[a][b][c]>=0)
        return dp[a][b][c];
    D=n+(a)*(dps(a-1,b,c))+(b)*(dps(a+1,b-1,c))+(c)*(dps(a,b+1,c-1));
    dp[a][b][c]=D/sum;
    return dp[a][b][c];
}
void solve()
{
    cin>>n;
    m=n;
    rep(i,0,n)
    {
        cin>>x;
        a[x]++;
    }
    // memset(dp,-1,sizeof(dp));
    rep(i,0,N)
    {
        rep(j,0,N)
        {
            rep(k,0,N)
            dp[i][j][k]=-1;
        }
    }
    cout<<setprecision(12)<<dps(a[1],a[2],a[3]);
    // cout<<setprecision(12)<<<<endl;
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
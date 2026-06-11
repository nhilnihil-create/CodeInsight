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
#define N  3005

ll dp[N][N];
ll pre(ll ind,ll l,ll r)
{
    if(l>r)
        return 0;
    return (dp[ind][r]-dp[ind][l-1]+hell)%hell;
}
void solve()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    rep(i,1,n+1)
    {
        dp[1][i]=1;
    }
    rep(i,2,n+1)
    {
        rep(j,1,i+1)
        {
            if(s[i-2]=='>')
            {
                dp[i][j]=(dp[i][j-1]+pre(i-1,j,i-1))%hell;
            }
            else
            {
                dp[i][j]=(dp[i][j-1]+pre(i-1,1,j-1))%hell;
            }
        }
    }
    ll ans=0;
    // rep(i,1,n+1)
    cout<<dp[n][n]<<endl;
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
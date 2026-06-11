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
#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
using namespace std;

using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define N  20005
ll n;
struct node
{
    ll w,s,v;
    void read()
    {
        cin>>w>>s>>v;
    }
};
bool cmp(node a,node b)
{
    return a.w+a.s<b.w+b.s;
}
vector<node>v(N);
void solve()
{
    cin>>n;
    rep(i,0,n)
    v[i].read();
    sort(all(v),cmp);
    vector<ll>dp(N);
    for(auto un:v)
    {
        for(int i=un.s;i>=0;i--)
        {
            dp[i+un.w]=max(dp[i+un.w],dp[i]+un.v);
        }
    }
    ll ans=0;
    for(auto u:dp)
        ans=max(ans,u);
    cout<<ans<<endl;

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
    time
    return 0;
}
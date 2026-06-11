#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define all(v) v.begin() , v.end()
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int mod = 998244353;
vector<int>v;
int dp[200000][20];
int solve(int n , int i)
{
    if(n<0) return 1e13;
    if(n == 0) return 0;
    if(i == v.size()) {
        if(n == 0) return 0;
        return 1e13;
    }

    if(dp[n][i] != -1) return dp[n][i];

    int ans=1e13;
    if(n >= v[i]) {
        ans=min(ans , 1+solve(n-v[i] , i+1));
        ans=min(ans , 1+solve(n-v[i] , i));
    }
    ans=min(ans , solve(n , i+1));

    return dp[n][i] = ans;
}


int32_t main()
{   fastio;

    int n;
    cin>>n;
    memset(dp , -1 , sizeof(dp));

    v.pb(1);
    int p=6;
    while(p<=100000)
    {
        v.pb(p);
        p *= 6;
    }
    int z=9;
    while(z<=100000)
    {
        v.pb(z);
        z *= 9;
    }

    cout<<solve(n , 0)<<"\n";

}

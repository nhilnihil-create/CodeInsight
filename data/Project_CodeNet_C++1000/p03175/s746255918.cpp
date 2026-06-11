/*
    author: kartik8800
*/
#include<bits/stdc++.h>
#define ll long long
#define fr(a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define triplet pair<int,pair<int,int>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

vector<int> tree[100001];
ll dp[100001][2];

ll solve(int u, bool constraint, int pr)
{
    if(dp[u][constraint] != -1)
        return dp[u][constraint];
    ll ans = 0;
    ll w1 = 1;
    for(int child : tree[u])
    {
        if(child != pr)
            w1 = (w1 * solve(child, 0, u)) % mod;
    }
    ans += w1;
    if(!constraint)
    {
     ll w2 = 1;
        for(int child : tree[u])
        {
            if(child != pr)
                w2 = (w2 * solve(child, 1, u)) % mod;
        }  
     ans = (ans + w2)%mod; 
    }
    return dp[u][constraint] = ans;
}

int main(){
    int n;
    cin>>n;
    memset(dp, -1, sizeof dp);
    for(int i=0; i < n-1; i++)
    {
        int u,v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    cout << solve(1, 0, -1);
    return 0;
}
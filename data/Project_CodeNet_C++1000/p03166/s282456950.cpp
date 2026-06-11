#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;
typedef array<ll,2> pll;
const ll NMAX=100005;
ll dp[NMAX],deg[NMAX];
vector<ll> edg[NMAX];

int main()
{
    ll n,m,ans=0;
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        deg[b]++;
        edg[a].push_back(b);
    }
    queue<ll> q;
    for(ll i=1;i<=n;i++){
        if(!deg[i]){
            q.push(i);
        }
    }
    while(!q.empty()){
        for(auto it : edg[q.front()]){
            dp[it]=max(dp[it],dp[q.front()]+1);
            deg[it]--;
            if(!deg[it])
                q.push(it);
        }
        ans=max(ans,dp[q.front()]);
        q.pop();
    }
    cout<<ans;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define deb(x) cout<< #x << " " << x << "\n";
#define MAX 9223372036854775807
#define MIN -9223372036854775807
#define PI 3.141592653589
#define setbits(n) __builtin_popcountll(n)
const ll mod=1e9+7;

const int N=1e5+1;
vector<ll> a[N],dp(N,-1);

ll dfs(ll v){
    if(dp[v]!=-1)
        return dp[v];
    ll mx=0;
    for(ll u: a[v])
        mx=max(mx,1+dfs(u));
    return dp[v]=mx;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();
    
    ll n,m;
    cin>>n>>m;
    vector<ll> in(n);
    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v; u--,v--;
        a[u].pb(v);
        in[v]++;
    }
    ll ans=0;
    for(ll i=0;i<n;i++)
        if(in[i]==0)
            ans=max(ans,dfs(i));
    cout<<ans;
    

    

    cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}
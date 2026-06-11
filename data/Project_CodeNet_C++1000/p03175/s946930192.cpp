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
vector<ll> a[N];
ll dp[N][2];

ll go(int node, int color,int p=-1){
    if(a[node].size()==1 && p!=-1 || a[node].size()==0) return 1;
    if(dp[node][color]!=-1)
        return dp[node][color];
    ll sum=1;
    for(ll u:a[node]){
        if(u==p) continue;
        ll ans=0;
        ans=(ans+go(u,0,node))%mod;
        if(color==0) ans=(ans+go(u,1,node))%mod;
        sum=(sum*ans)%mod;
    }
    //if(sum==0) cout<<node<<" "<<color<<"\n";
    return dp[node][color]=sum;
} 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();
    
    ll n;
    cin>>n;
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v; u--,v--;
        a[u].pb(v);
        a[v].pb(u);
    }
    memset(dp,-1,sizeof(dp));
    cout<<(go(0,1)+go(0,0))%mod;


 
 
    cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}
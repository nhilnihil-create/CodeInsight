//Author rahuliitkgp

/*A thing of beauty is a joy forever,
Its loveliness increases,
it will never pass into nothingness.*/
//Men at Work :)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long int ll;

#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define ps(x,y)         fixed<<setprecision(y)<<x
#define w(x)            int x; cin>>x; while(x--)
#define INF (int)1e9 + (int)1e8
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void cpp(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

class graph{
public:
    vector<ll>* adjList;
    vector<vector<ll> > dp;
    graph(ll n){
        adjList = new vector<ll>[n];
        dp = vector<vector<ll> >(n, vector<ll>(2, -1));
    }
    void addEdge(ll u, ll v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    ll dfs(ll curr, ll par, ll color){
        if(dp[curr][color]!=-1) return dp[curr][color];
        ll ans1 = 1;
        for(auto ch: adjList[curr]){
            if(ch!=par){
                if(color==1){
                    ans1*=((dfs(ch, curr, 1)+dfs(ch, curr, 0))%mod);
                    ans1%=mod;
                }
                else{
                    ans1*=dfs(ch, curr, 1);
                    ans1%=mod;
                }
            }
        }
        return dp[curr][color]=ans1;
    }
};

int main(){
    cpp();
    ll n;
    cin>>n;
    graph g(n);
    for(ll i=0; i<n-1; i++){
        ll x, y;
        cin>>x>>y;
        g.addEdge(--x, --y);
    }
    ll ans = (g.dfs(0, -1, 1)+g.dfs(0, -1, 0))%mod;
    cout<<ans<<endl;
    return 0;
}





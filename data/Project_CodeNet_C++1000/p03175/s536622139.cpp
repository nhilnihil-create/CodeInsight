#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define fo(i,CApiTaL_N) for(int i=0; i<CApiTaL_N; i++)
#define Fo(i,k,CApiTaL_N) for(int i=k; i<CApiTaL_N; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define tr(it, a) for(auto it=a.begin(); it!=a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

int t;
int n;
const int mxN=1e5, mod=1e9+7;
vvi tree(mxN+1);
vvl dp(mxN+1,vl(2));

ll mul_self(ll a, ll b){
    return (a*b)%mod;
}

ll add_self(ll a, ll b){
    return (a+b)%mod;
}

void dfs(int node, int par){
    if(tree[node].size()==1&&tree[node][0]==par){
        dp[node]={1,1};
        return;
    }
    ll wt=0, blk=1;
    for(auto child:tree[node]){
        if(child!=par){
            dfs(child,node);
            auto temp=blk;
            blk=mul_self(blk,dp[child][1]);
            wt=add_self(mul_self(temp,dp[child][0]), mul_self(wt,add_self(dp[child][0],dp[child][1])));
            // cout<<child<<" "<<blk<<" "<<wt<<endl;
        }
    }
    dp[node]={blk,wt+blk};
}

void test_case(){
    cin>>n;
    fo(i,n-1){
        int a,b;
        cin>>a>>b;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    dfs(1,-1);
    cout<<add_self(dp[1][0],dp[1][1])<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    t=1;
    while(t--){
        test_case();
    }
    
    return 0;
}
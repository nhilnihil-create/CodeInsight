#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define ll long long int

ll mod=1e9+7;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> tree(n);
    int u,v;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        u--,v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<ll> bl(n);
    vector<ll> wh(n);

    function<void(int,int)> dfs_exp=[&](int node,int parent){ 
        int cnt=0;
        for(auto v:tree[node]){
            if(v!=parent){
                dfs_exp(v,node);
                cnt++;
            }
        }
        ll wh_ways=1;
        ll bl_ways=1;
        for(auto v:tree[node]){
            if(v!=parent){
                bl_ways*=wh[v];
                wh_ways*=bl[v];
            }
            bl_ways%=mod;
            wh_ways%=mod;
        }
        bl[node]=bl_ways;
        wh[node]=(bl_ways+wh_ways)%mod;
    };
    dfs_exp(0,-1);
    debug(bl);
    debug(wh);
    cout<<wh[0]<<"\n";
    return 0;
}
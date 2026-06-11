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

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].push_back(v);
    }
    vector<int> max_chain(n,-1);
    function<int(int)> dfs=[&](int node){
        if(max_chain[node]!=-1)return max_chain[node];
        max_chain[node]=1;
        for(auto v:g[node]){
            max_chain[node]=max(max_chain[node],dfs(v)+1);
        }
        return max_chain[node];
    };

    for(int i=0;i<n;i++){
        if(max_chain[i]==-1){
            max_chain[i]=dfs(i);
        }
        //debug(max_chain);
    }
    cout<<*max_element(max_chain.begin(),max_chain.end())-1<<"\n";
    return 0;
}
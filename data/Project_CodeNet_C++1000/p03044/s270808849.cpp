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
    int n;
    scanf("%d",&n);
    vector<vector<pair<int,ll>>> tree(n);
    vector<int> color(n,-1);
    int u,v;
    ll w;
    for(int i=0;i<n-1;i++){
        scanf("%d%d%lld",&u,&v,&w);
        u--,v--;
        tree[u].push_back({v,w});
        tree[v].push_back({u,w});
    }
    function<void(int,int,ll)> dfs=[&](int node,int parent,ll path){
        if(path%2==0){
            color[node]=2;
        }
        else{
            color[node]=1;
        }
        for(auto v:tree[node]){
            if(v.first==parent)continue;
            dfs(v.first,node,path+v.second);
        }
        return;
    };
    dfs(0,-1,0);
    for(int i=0;i<n;i++){
        cout<<color[i]%2<<"\n";
    }
    return 0;
}
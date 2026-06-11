#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
const int max_n= 100000;
long long cnt[111];
long long n,a=0,b,W,L,kk,c,m,V,e;
const int INF = 1e9+1;
const int mod = 1e9 + 7;
int mincost[max_n];
string s1,s2;
int prev[max_n];
long long x[max_n],y[max_n],s[max_n],d[max_n],ppar[max_n],rrank[max_n],spf[max_n],co[max_n];
typedef pair<long , long> pii;
pii cow[max_n];
//int cost[max_n][max_n];
pii bo[max_n];
int color[max_n];
vector<long long> G[max_n];
bool used[max_n];
struct edge{
    int u,cost,v;
};
bool comp(const edge& e1, const edge& e2){
    return e1.cost < e2.cost;   
}
edge es[max_n];
typedef pair<int, int> P;
struct Cmp{
    bool operator()(const pii &a,const pii &b){
        return a.second > b.second;
    }
};
void init(int n){
    for(int i=0 ; i<n ; i++){
        ppar[i] = i;
        rrank[i] = 0;
    }
}
int find(int x){
    if(ppar[x] == x){
        return x;
    }else{
        return ppar[x] = find(ppar[x]);
    }
}
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y)  return;

    if(rrank[x] < rrank[y]){
        ppar[x] = y;
    }else{
        ppar[y] = x;
        if(rrank[x] == rrank[y])  rrank[x]++;
    }
}
bool same(int x, int y){
    return find(x) == find(y);
}
bool nibu_match(int v, int c){
    color[v] = c;
    for(int i=0 ; i<G[v].size() ; i++){
        int vv = G[v][i];
        if(color[vv] == c){
            return false;
        }
        if(color[vv] == 0 && !nibu_match(vv, -c)){
            return false;
        }
    }
    return true;
}
void solve(){
    if(nibu_match(0,1)){
        long long B = 0, W = 0;
        for(int i=0 ; i<V ; i++){
            if(color[i] == 1)   B++;
        }
        W = V-B;
        cout << B*W-e << endl;
        return;
    }else{
        cout << (V*(V-1))/2 - e << endl;
    }
}
int main(){
    cin >> V >> e;
    for(int i=0 ; i<e ; i++){
        int xx; int yy;
        cin >> xx >> yy;
        xx--;   yy--;
        G[xx].push_back(yy);
        G[yy].push_back(xx);
    }
    solve();
    return 0;
}
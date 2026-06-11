#include <cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include <cmath>
#include <iomanip>
#include <regex>
#include <queue>
#include <set>
using namespace std;
using ll = long long;
using Lf = long double;
using plong = pair<ll,ll>;
const int MOD = 1000000007;
struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};
int main(){
    ll N,M;
    cin>>N>>M;
    UnionFind uf(N);
    vector<ll> p(N);
    for(ll i=0;i<N;i++){
        cin>>p[i];
        p[i]--;
    }
    for(ll i=0;i<M;i++){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        uf.merge(a,b);
    }
    ll res=0;
    for(ll i=0;i<N;i++){
        if(uf.root(p[i])==uf.root(i))res++;
    }
    cout<<res<<endl;



}
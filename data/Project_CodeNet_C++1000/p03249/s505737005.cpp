#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define int long long
class UnionFind {
private:
    int sz;
    vector<int> par, size_;
public:
    UnionFind(){}
    UnionFind(int node_size) : sz(node_size), par(sz), size_(sz, 1){
        iota(par.begin(), par.end(), 0);
    }
    int find(int x){
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }
    void unite(int x,int y){
        x = find(x), y = find(y);
        if(x == y) return;
        if(size_[x] < size_[y]) swap(x,y);
        par[y] = x;
        size_[x] += size_[y];
    }
    int size(int x){
        x = find(x);
        return size_[x];
    }
    bool same(int x,int y){
        return find(x) == find(y);
    }
};

vector<vector<int> > gg;
pair<int,int> dfs(int id,int pre){
    pair<int,int> sm = MP(0,0);
    for(auto x:gg[id]){
        if(x!=pre){
            pair<int,int> tmp = dfs(x,id);
            sm.first += tmp.first;
            sm.second += tmp.second;
        }
    }
    sm.second += sm.first;
    sm.first++;
    return sm;
}


signed main(){
    int n;
    cin >> n;
    UnionFind uf(n+1);
    vector<pair<int,int> > v;
    map<int,int> p;
    rep(i,n){
        int d;
        cin >> d;
        p[d] = i+1;
        v.push_back(MP(d,i+1));
    }
    sort(v.begin(),v.end(),greater<pair<int,int> >());
    map<int,int> mp;
    gg.resize(n+1);
    vector<pair<int,int> > g;
    bool ng = 1;
    rep(i,n){
        int k = v[i].first;
        int u = v[i].second;
        int c = mp[k];
        c++;
        //cerr << k << " " << u << " " << c << endl;
        if(c==n&&i==n-1){
            ng = 0;
            continue;
        }
        int nxt = k - (n-c-c);
        if(p.find(nxt)==p.end()){
            cout << -1 << endl;
            return 0;
        }
        mp[nxt]+=c;
        g.push_back(MP(u,p[nxt]));
        gg[u].push_back(p[nxt]);
        gg[p[nxt]].push_back(u);
        uf.unite(u,p[nxt]);
    }
    for(int i=1;i<=n;i++){
        if(!uf.same(i,1)){
            cout << -1 << endl;
            return 0;
        }
    }
    if(ng){
        cout << -1 << endl;
        return 0;
    }
    if(dfs(v[n-1].second,-1).second!=v[n-1].first){
        cout << -1 << endl;
        return 0;
    }
    for(auto x:g){

        cout << x.first << " " << x.second << endl;
    }
    return 0;
}

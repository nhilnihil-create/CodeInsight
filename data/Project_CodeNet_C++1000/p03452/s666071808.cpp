#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class Abel> struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<Abel> diff_weight;

    UnionFind(int n = 1, Abel SUM_UNITY = 0) {
        init(n, SUM_UNITY);
    }

    void init(int n = 1, Abel SUM_UNITY = 0) {
        par.resize(n); rank.resize(n); diff_weight.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
    }

    //xの根を求める
    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    //xの重みを計算する
    Abel weight(int x) {
        root(x);
        return diff_weight[x];
        }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    //x,yを重みwでマージする
    bool merge(int x, int y, Abel w) {
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    //xとyの差を計算する
    Abel diff(int x, int y) {
        return weight(y) - weight(x);
    }
};



int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    ll n,m;
    cin>>n>>m;
    UnionFind<ll> uni(n);
    int l[m],r[m],d[m];
    for(int i=0;i<m;i++){
        cin>>l[i]>>r[i]>>d[i];
        l[i]--,r[i]--;
        uni.merge(l[i],r[i],d[i]);
    }
    bool pos=true;
    for(int i=0;i<m;i++){
        if(uni.diff(l[i],r[i]) != d[i]) pos = false;
    }
    if(pos) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
}

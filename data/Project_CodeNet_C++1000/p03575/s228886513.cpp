#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<long long, long long>;
const long long INF = 1001001001;
const long long MOD = 1000000007;
const double EPS = 1e-10;

struct UnionFind {
    vector<int> d;
    int cc_cnt;
    UnionFind(int n): d(n, -1) { cc_cnt = n; }
    int find(int x) {
        if(d[x] < 0) return x;
        return d[x] = find(d[x]);
    }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        if(d[x] > d[y]) swap(x, y);
        d[x] += d[y];
        d[y] = x;
        cc_cnt--;
        return true;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return -d[find(x)]; }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;
    int a[m],b[m];
    for(int i=0;i<m;i++){
        cin>>a[i]>>b[i];
        a[i]--; b[i]--;
    }
    int ans=0;
    for(int i=0;i<m;i++){
        UnionFind uf(n);
        for(int j=0;j<m;j++){
            if(j==i)continue;
            uf.unite(a[j],b[j]);
        }
        if(uf.cc_cnt>1)ans++;
    }
    cout<<ans<<endl;
}
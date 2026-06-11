#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
struct UnionFind{
vector<int> par,depth;
UnionFind(int n){
par.resize(n); depth.resize(n);
for(int i=0; i<n; i++){
par[i]=i;
depth[i]=0;
}
}
int find(int x){
if(par[x]==x){
return x;
}
else{
return par[x]=find(par[x]);
}
}
bool same(int x, int y){
return find(x)==find(y);
}
void unite(int x, int y){
x=find(x); y=find(y);
if(x==y) return;
if(depth[x]<depth[y]) swap(x,y);
if(depth[x]==depth[y]) depth[x]++;
par[y]=x;
}
};
int main() {
    int n,m;
    cin >> n >> m;
    vector<int> p(n);
    UnionFind uf(n);
    for(int i=0; i<n; i++){
        cin >> p[i];
        p[i]--;
    }
    for(int i=0; i<m; i++){
        int x,y; cin >> x >> y;
        x--; y--;
        uf.unite(x,y);
    }
    int ans=0;
    for(int i=0; i<n; i++){
        if(uf.same(i,p[i])) ans++;
    }
    cout << ans << endl;
    return 0;
}
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

struct WeightedUnionFind{
    vector<int> par; // 親の番号
    vector<int> ws;  // 親との重みの差
    
    WeightedUnionFind(int n) : par(n,-1), ws(n,0){}
    
    int find(int x){
        if(par[x] < 0){
            return x;
        }else{
            int parent = find(par[x]);
            ws[x] += ws[par[x]];
            return par[x] = parent;
        }
    }
    
    int weight(int x){
        find(x); 
        return ws[x];
    }
    
    bool unite(int x, int y, int w){ // x <-(w)- y (x + w = y)
        w += weight(x); 
        w -= weight(y);
        x = find(x); y = find(y);
        
        if(x != y){
            if(par[y] < par[x]) {  // 多い方が根になるようにスワップする.
                int tmp = x; x = y; y = tmp; w = -w;
            }
            par[x] += par[y]; par[y] = x;
            ws[y] = w;
            return true;
        }else{
            return false;
        }
    }
    
    bool same(int x, int y){
        return find(x) == find(y);
    }
    
    void init(int size){
        for(int i=0;i<size;i++){
            par[i]=-1;
            ws[i]=0;
        }
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,m;cin>>n>>m;
    WeightedUnionFind uf(111111);
    bool f=true;
    for(int i=0;i<m;i++){
        int l,r,d;cin>>l>>r>>d;l--;r--;
        if(uf.same(l,r)){
            if(uf.weight(r)-uf.weight(l)!=d) f=false;
        }
        else{
            uf.unite(l,r,d);
        }
    }
    if(f) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

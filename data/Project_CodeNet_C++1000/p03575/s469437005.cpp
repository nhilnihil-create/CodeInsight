#include <bits/stdc++.h>
using namespace std;


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

using pint = pair<int,int>;
int main(void){
    int N,M;
    cin >> N >> M;
    vector<pair<int,int>> p(M,pair<int,int>(0,0));
    for(int i = 0; i < M;i++){
        cin >> p[i].first >> p[i].second;
        p[i].first--,p[i].second--;
    }
    //for(int i = 0; i < M;i++)cout << p[i].first <<" "<< p[i].second<<endl;
    int ans = 0;
    for(int i = 0;i < M;i++){
        UnionFind uf(N);
        for(int j = 0;j < M;j++){
            
            if(i == j)continue;
            
            uf.merge(p[j].first,p[j].second);
            
        }
        
        set<int> judge;
        for(int j = 0;j < N;j++){
            //cout <<"##"<< uf.root(j) << endl;
            judge.insert(uf.root(j));
            
        }
        
        //cout << judge.size() << endl;
        if(judge.size()==2) ans++;
    
    }
    cout << ans << endl;
    
}

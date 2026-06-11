#include<bits/stdc++.h>
using namespace std;
struct UnionFind{
    vector<int>par;

    UnionFind(int n):par(n){
        for(int i=0;i<n;i++)par[i] = i;
    }
    int find(int x){
        if(par[x] == x)return x;
        else return par[x] = find(par[x]);
    }
    void unite(int x,int y){
        int rx = find(x);
        int ry = find(y);
        if(rx != ry)par[rx] = ry;
    }
    bool same(int x,int y){
        return find(x)==find(y);
    }
};
int main(){
    long n,m;
    cin >> n >> m;
    long x[m];
    long y[m];
    long z[m];
    for(int i=0;i<m;i++){
        cin >>  x[i] >> y[i] >> z[i];
        x[i]--;
        y[i]--;
    }

    UnionFind unif(n);

    for(int i=0;i<m;i++){
        unif.unite(x[i],y[i]);
    }
    set<int>s;
    for(int i=0;i<n;i++){
        s.insert(unif.find(i));
    }
    cout << s.size() << endl;
    


}
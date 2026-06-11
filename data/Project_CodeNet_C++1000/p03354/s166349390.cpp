#include <bits/stdc++.h>
using namespace std;

struct UnionFind{
    int num;

    vector<int> rs,ps;

    UnionFind(){}

    UnionFind(int n) : num(n),rs(n,1),ps(n,0){iota(ps.begin(),ps.end(),0);}

    int find(int x){
        return ( x==ps[x] ? x: ps[x] = find(ps[x]));
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }

    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(rs[x] < rs[y]) swap(x,y);
        rs[x] += rs[y];
        ps[y] = x;
        num--;
    }

    int size(int x){
        return rs[find(x)];
    }

    int count() const{
        return num;
    }

};

int main(){
    int N,M;
    cin>>N>>M;
    vector<int> p(N);
    UnionFind U(N);
    for(int i=0; i<N; i++){
        cin>>p[i];
        p[i]--;
    }

    for(int i=0; i<M; i++){
        int x,y;
        cin>>x>>y;
        x--,y--;
        U.unite(x,y);
    }

    int cnt = 0;

    for(int i=0; i<N; i++){
        if(U.same(p[i],i)) cnt++;
    }

    cout<<cnt<<endl;

    return 0;
}
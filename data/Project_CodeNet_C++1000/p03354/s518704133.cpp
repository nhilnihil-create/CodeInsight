#include <bits/stdc++.h>

class UnionFind{
private:
    std::vector<int> parent;
    std::vector<int> size;
    
public:
    UnionFind(int N){
        parent.resize(N);
        size.resize(N);
        for(int i = 0; i < N; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int root(int x){
        if (parent[x] == x) return x;
        int rx = root(parent[x]);
        parent[x] = rx;
        return rx;
    }

    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        parent[rx] = ry;
        size[ry] += size[rx];
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
    
    int get_size(int x){
        return size[root(x)];
    }
};

int main(){
    int N, M;
    std::cin >> N >> M;
    std::vector< int > P(N);
    for(int i=0; i<N; i++){
        std::cin >> P[i];
    }
    UnionFind tree(N);
    for(int i=0; i<M; i++){
        int tmp1, tmp2;
        std::cin >> tmp1 >> tmp2;
        tree.unite(tmp1-1, tmp2-1);
    }
    
    int ans = 0;
    for(int i=0; i<N; i++){
        if(tree.same(i, P[i]-1)){
            ans++;
        }
    }
    
    
    std::cout << ans << std::endl;
    
    return 0;
    
}

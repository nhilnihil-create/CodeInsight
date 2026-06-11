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
    std::vector< int > X(M);
    std::vector< int > Y(M);
    std::vector< int > Z(M);
    UnionFind tree(N);
    for(int i=0; i<M; i++){
        std::cin >> X[i] >> Y[i] >> Z[i];
        tree.unite(X[i]-1, Y[i]-1);
    }
    
    std::map< int, bool > mp;
    int cnt = 0;
    for(int i=0; i<N; i++){
        int r = tree.root(i);
        auto itr = mp.find(r);
        if(itr == mp.end()){
            mp[r] = true;
            cnt++;
        }
    }
    
    std::cout << cnt << std::endl;
    
    return 0;
}


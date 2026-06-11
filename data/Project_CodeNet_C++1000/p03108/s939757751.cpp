#include<iostream>
#include<vector>

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
    UnionFind tree(N);
    std::vector< int > A(M);
    std::vector< int > B(M);
    for(int i=0; i<M; i++){
        std::cin >> A[i] >> B[i];
    }
    
    std::vector< long long > ans(M);
    ans[0] = 0;
    ans[M-1] = (long long)N * ((long long)N - 1) / 2;
    
    for(int i=M-1; i>0; i--){
        long long tmp = 0;
        if(!tree.same(A[i] - 1, B[i] - 1)){
            tmp = (long long)tree.get_size(A[i] - 1) * (long long)tree.get_size(B[i] - 1);
        }
        tree.unite(A[i] - 1, B[i] - 1);
        ans[i-1] = ans[i] - tmp;
    }
    
    for(int i=0; i<M; i++){
        std::cout << ans[i] << std::endl;;
    }
    
    return 0;
    
}

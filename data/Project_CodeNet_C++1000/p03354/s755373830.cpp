#include <iostream>
#include <vector>

class UnionFind {
private:
    std::vector<int> parent;
public:
    UnionFind(int n) : parent(n){
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    bool isSame(int x, int y){
        return root(x) == root(y);
    }
    int root(int x){
        if(parent[x] == x){
            return x;
        }else{
            return parent[x] = root(parent[x]);
        }
    }
    void unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x != y){
            parent[x] = y;
        }
    }
};

int main(){
    int n, m;
    std::cin >> n >> m;
    UnionFind ufGraphs = UnionFind(n+1); // 1-indexed
    int permutation[100010];
    for(int i = 0; i < n; i++){
        int p;
        std::cin >> p;
        permutation[i] = p;
    }
    for(int i = 0; i < m; i++){
        int x, y;
        std::cin >> x >> y;
        ufGraphs.unite(x,y);
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(ufGraphs.isSame(i+1, permutation[i])) cnt++;
    }
    std::cout << cnt << std::endl;
}

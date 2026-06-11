#include <iostream>
#include <vector>
using namespace std;
struct UnionFind{
    vector<int> par;
    vector<long long> rank;
    void init(int n){
        par.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; i++){
            par[i] = i;
            rank[i] = 1;
        }
    }
    int root(int x){
        if(par[x] == x) return x;
        return root(par[x]);
    }
    bool same(int x, int y){
        return root(x) == root(y);
    }
    long long size(int x){
        return rank[(root(x))];
    }
    void unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(size(y) > size(x)) swap(x, y);
        rank[x] += rank[y];
        par[y] = par[x]; 
    }
};
int main(){
    long long N, M;
    cin >> N >> M;
    long long m = N * (N - 1) /2;
    vector<int> A(M), B(M);
    for(int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }
    UnionFind U;
    vector<long long> sum(M, m);
    U.init(N);
    for(int i = 0; i < M - 1; i++){
        int a = A[M - 1 - i], b = B[M - 1 - i];
        if(U.same(a, b)) {
            sum[M - 2 - i] = m;
            continue;
        }
        long long t = U.size(b) * U.size(a);
        U.unite(a, b);
        m -= t;
        sum[M - 2 - i] = m;
    }
    for(int i = 0; i < M; i++) cout << sum[i] << endl;
}
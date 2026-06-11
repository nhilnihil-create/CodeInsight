#include<iostream>
#include<vector>
using namespace std;

long long fubendo;

struct UnionFind{
    vector<long long> root;
    vector<long long> sizes;
    UnionFind(long long n): root(n + 1), sizes(n + 1,1){
        for(long long i = 0; i <= n; i++) root[i] = i;
    }
    long long find(long long x){
        if(x == root[x]) return x;
        return root[x] = find(root[x]);
    }
    void unite(long long x, long long y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        fubendo -= sizes[x]*sizes[y];
        if(sizes[x] < sizes[y]) swap(x,y);
        root[y] = x;
        sizes[x] += sizes[y];
    }
    bool same(long long x, long long y){
        return find(x) == find(y);
    }
};

int main(){
    //input
    long long N, M;
    cin >> N >> M;
    long long i,A[M+1],B[M+1];
    for(i=1; i<=M; i++){
        cin >> A[i] >> B[i];
    }

    //calc
    fubendo = N*(N-1)/2;
    long long fuben_when[M+1];
    UnionFind uf(N);
    for(i=M; i>=1; i--){
        fuben_when[i]=fubendo;
        uf.unite(A[i],B[i]);
    }
    
    //answer
    for(i=1; i<=M; i++){
        cout << fuben_when[i] << endl;
    }
    system("pause");
    return 0;
}
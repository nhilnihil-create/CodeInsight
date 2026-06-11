#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init(int * par, int * rank, int n){
    for(int i =0; i<n; i++){
        par[i] = i;
        rank[i] = 0;
    }
}

int find(int * par, int * rank, int x){
    if(par[x] == x) return x;
    else return find(par, rank, par[x]);
}

void unite(int * par, int * rank, int x, int y){
    x = find(par, rank, x);
    y = find(par, rank, y);
    if(x == y)  return;

    if(rank[x] < rank[y]){
        par[x] = y;
    }
    else{
        par[y] = x;
        if(rank[x] == rank[y]) rank[x]++;
    }
}

bool same(int * par, int * rank, int x, int y){
    return find(par, rank, x) == find(par, rank, y);
}

int main(){
    int N, M; 
    cin >> N >> M;
    int p[N];
    for(int i=0; i<N; i++){
        cin >> p[i];
        p[i]--;
    }
    int par[N], rank[N];
    init(par, rank, N);
    
    for(int i=0; i<M; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        unite(par, rank, x, y);
    }
    int ans = 0;
    for(int i=0; i<N; i++) if(same(par, rank, p[i], i)) ans ++;
    cout << ans << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;

template<typename T> class WeightedUnionFind{
    protected:
        vector<int> par;
        vector<T> w;
    public:
        WeightedUnionFind(int n);
        int root(int x);
        bool unite(int x, int y, T w);
        bool same(int x, int y);
        T weight(int x);
        T diff(int x, int y);
};

template<typename T> WeightedUnionFind<T>::WeightedUnionFind(int n){
    par = vector<int>(n + 1, -1);
    w = vector<T>(n + 1);
}

template<typename T> int WeightedUnionFind<T>::root(int x){
    if (par[x] < 0) return x;
    int r = root(par[x]);
    w[x] += w[par[x]];
    return par[x] = r;
}

template<typename T> bool WeightedUnionFind<T>::unite(int x, int y, T d){
    d += weight(x); d -= weight(y);
    x = root(x); y = root(y);
    if (x == y) return d == 0;
    if (par[x] > par[y]){
        swap(x, y);
        d = -d;
    }
    par[x] += par[y];
    par[y] = x;
    w[y] = d;
    return true;
}

template<typename T> bool WeightedUnionFind<T>::same(int x, int y){
    return root(x) == root(y);
}

template<typename T> T WeightedUnionFind<T>::weight(int x){
    root(x);
    return w[x];
}

template<typename T> T WeightedUnionFind<T>::diff(int x, int y){
    return weight(y) - weight(x);
}



int main(){
    int n, m;
    cin >> n >> m;
    WeightedUnionFind<ll> wuf(n);
    for (int i = 0; i < m; i++){
        int l, r, d;
        cin >> l >> r >> d;
        if (!wuf.unite(l, r, d)){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    
    return 0;
}
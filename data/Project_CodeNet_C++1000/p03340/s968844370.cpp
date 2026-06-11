#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; (i) < (n); (i)++)
using namespace std;

struct Edge{
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

long modpow(long a, long n, long mod) {
    long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// a^{-1} mod を計算する
long modinv(long a, long mod) {
    return modpow(a, mod - 2, mod);
}

struct compare1 { 
    bool operator()(const pair<long, long>& value,  
                                const long& key) 
    { 
        return (value.first < key); 
    } 
    bool operator()(const long& key,  
                    const pair<long, long>& value) 
    { 
        return (key < value.first); 
    } 
};

struct UnionFind {
    vector<int> par;
    vector<int> rank;

    UnionFind(int n = 1){
        init(n);
    }

    void init(int n = 1){
        par.resize(n);
        rank.resize(n);
        REP(i, n) par[i] = i, rank[i] = 0; 
    }

    int root(int x){
        if(par[x] == x) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y){
        return root(x) == root(y);
    }

    bool merge(int x, int y){
        x = root(x); y = root(y);
        if(x == y) return false;
        if(rank[x] < rank[y]) swap(x, y);
        if(rank[x] == rank[y]) rank[x]++;
        par[y] = x;
        return true;
    }
};

template<class Abel> struct weightedUnionFind{
    vector<int> par;
    vector<int> rank;
    vector<Abel> diff_weight;

    weightedUnionFind(int n = 1, Abel SUM_UNITY = 0){
        init(n, SUM_UNITY);
    }

    void init(int n = 1, Abel SUM_UNITY = 0){
        par.resize(n); rank.resize(n); diff_weight.resize(n);
        REP(i, n) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY; 
    }

    int root(int x){
        if(par[x] == x) return x;
        else{
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    Abel weight(int x){
        root(x);
        return diff_weight[x];
    }

    bool issame(int x, int y){
        return root(x) == root(y);
    }

    bool merge(int x, int y, Abel w){
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if(x == y) return false;
        if(rank[x] < rank[y]) swap(x, y), w = -w;
        if(rank[x] == rank[y]) rank[x]++;
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    Abel diff(int x, int y){
        return weight(y) - weight(x);
    }
};

using Graph = vector<vector<Edge>>;
using P = pair<int, int>;

int main()
{
    long N; cin >> N;
    long A[200005];
    for(long i = 0; i < N; i++) cin >> A[i];
    
    long r = 0;
    long ans = 0;
    long temp = 0;
    for(long l = 0; l < N; l++){
        while(temp + A[r] == (temp ^ A[r]) && r < N){
            temp += A[r];
            r++;
        }
        ans += r-l;
        temp -= A[l];
        //cout << l << " " << r << endl;
    }
    cout << ans << endl;
    return 0;
}


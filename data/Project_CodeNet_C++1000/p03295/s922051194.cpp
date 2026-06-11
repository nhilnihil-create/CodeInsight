#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const i64 MOD = 1e9 + 7;
const i64 INF = i64(1e18) + 7;

template <typename T>
bool chmin(T& x, T y){
    if(x > y){
        x = y;
        return true;
    }
    return false;
}

template <typename T>
bool chmax(T& x, T y){
    if(x < y){
        x = y;
        return true;
    }
    return false;
}

struct UnionFind{
    vector<int> par;
    int count;
    UnionFind(int n) : par(n, -1), count(0){}
    int Find(int x){return par[x] < 0 ? x : Find(par[x]);}
    int Size(int x){return par[x] < 0 ? -par[x] : Size(par[x]);}
    bool Unite(int x, int y){
        x = Find(x);
        y = Find(y);
        if(x == y)
            return false;
        if(par[x] > par[y])
            swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return ++count;
    }
};



signed main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    vector<int> pos(n, -1);
    for(int i = 0; i < m; ++i){
        cin >> a[i] >> b[i];
        --a[i], --b[i];
        chmax(pos[b[i]], a[i]);
    }
    int ma = 0;
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        if(ma <= pos[i]){
            ma = i;
            ++cnt;
        }
    }
    cout << cnt << endl;
}

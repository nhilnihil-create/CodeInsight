#include <bits/stdc++.h>

#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define ACC(c) (accumulate(ALL(c), 0LL))
#define ENDL "\n"
#define PRINT(x) cout << (x) << ENDL

using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;

inline int in(int& a) {return scanf("%d", &a);}
inline void out(int n) {printf("%d\n", n);}
auto pint_compare = [](pint x, pint y) -> bool{return (x.first < y.first);};


ll N, M;
int color[100000];
vector<int> adj[100000];

bool dfs(int ver, int col){
    if(color[ver] == 1 - col){
        return false;
    }else if(color[ver] == col){
        return true;
    }
    color[ver] = col;
    bool ret = true;
    for(int next : adj[ver]){
        ret = ret && dfs(next, 1 - col);
    }
    return ret;
}

signed main(){
    cin >> N >> M;
    int A, B;
    REP(i, N) color[i] = -1;
    REP(i, M){
        cin >> A >> B;
        adj[A - 1].push_back(B - 1);
        adj[B - 1].push_back(A - 1);
    }
    if(dfs(0, 0)){
        ll w = 0;
        REP(i, N) w += color[i];
        PRINT(w * (N - w) - M);
    }else{
        PRINT(N * (N - 1) / 2 - M);
    }
    return 0;
}
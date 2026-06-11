#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define FORR(i,m,n) for(int i = m - 1; i >= n; i--)
#define ALL(v) v.begin(), v.end()
#define itn int
#define Yes() cout << "Yes" << endl
#define No() cout << "No" << endl
#define YES() cout << "YES" << endl
#define NO() cout << "NO" << endl
#define println(x) cout << x << endl
#define print(x) cout << x << " "
template<typename T, typename U>
inline bool CMAX(T &m, U x) { if (m < x) { m = x; return true; } return false; }
template<typename T, typename U>
inline bool CMIN(T &m, U x) { if (m > x) { m = x; return true; } return false; }

typedef long long lint;
typedef long double ldouble;
const int INF = 1e9;
const lint LINF = 1e18;
const int MOD = 1e9+7;
vector<int> g;

int root (int x){
    if(g[x] == x) return x;
    else return g[x] = root(g[x]);
}
bool same (int x,int y){
    return g[x] == g[y];
}
void unite(int x,int y){
    x = root(x);
    y = root(y);
    if(x == y) return;
    g[x] = y;
}
int main(){
    int n,m;
    cin >> n >> m;
    int ans = 0;
    g = vector<int>(n);
    vector<pair<int,int>> keiro(m);
    REP(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        keiro[i].first = a;
        keiro[i].second = b;
    } 
    REP(i,m){
        REP(j,n) g[j] = j;
        REP(j,m){
            if(i == j) continue;
            unite(keiro[j].first,keiro[j].second);
        }
        int temp = root(g[0]);
        REP(j,n){
            if(root(j) != temp){ ans++;break;}
        }
    }
    println(ans);
    return 0;
}
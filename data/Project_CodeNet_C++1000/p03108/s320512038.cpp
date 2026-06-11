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

vector<lint> g;
vector<lint> p;
void init(int n){
    REP(i,n) {g[i] = i; p[i] = 1;}
}

int root(int x){
    if(g[x] == x) return x;
    else return g[x] = root(g[x]);
}
bool unite(int x,int y){
    x = root(x);
    y = root(y);
    if(x == y) return false;
    if(p[x] < p[y]) swap(x,y);
    p[x] += p[y];
    g[y] = x;
    return true;
    
}
int len(int x){
    return p[root(x)];
}
bool same(int x,int y){
    return root(x) == root(y);
}
int main(){
    int n,m;
    cin >> n >> m;
    g = vector<lint>(n);
    p = vector<lint> (n);
    vector<pair<int,int>> hasi(m);
    vector<lint> ans(m);
    REP(i,m){
        int a,b;
        cin >> a >>b;
        a--;b--;
        hasi[i].first = a;
        hasi[i].second = b;
    }
    init(n);
    ans[m - 1] = (lint(n)*lint((n - 1))) / 2;
    REPR(i,m){
        if(i == 0) break;
        if(same(hasi[i].first,hasi[i].second)){
            ans[i - 1] = ans[i];
            unite(hasi[i].first,hasi[i].second);
        }else{
            ans[i - 1] = ans[i] - lint(len(hasi[i].first)) * lint(len(hasi[i].second));
            unite(hasi[i].first,hasi[i].second);
        }
    }
    REP(i,m) println(ans[i]);
    return 0;
}
#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<lint, lint> pll;
typedef complex<double> xy_t;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}

constexpr lint mod = 1e9+7;
constexpr lint INF = mod*mod;
constexpr int MAX = 100010;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    string s;
    cin>>s;
    set<int> G[n];
    int a[n], b[n];
    bool ok[n];
    rep(i, n){
        a[i]=b[i]=0;
        ok[i]=true;
    }
    rep(i, m){
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        G[x].insert(y);
        G[y].insert(x);
    }

    rep(v, n)for(int nv: G[v]){
        if(s[nv]=='A') ++a[v];
        else ++b[v];
    }
    queue<int> que;
    rep(i, n)if(!a[i] || !b[i]){
        que.push(i);
        ok[i]=false;
    }
    while(!que.empty()){
        int v=que.front(); que.pop();
        for(int nv: G[v])if(ok[nv]){
            if(s[v]=='A') --a[nv];
            else --b[nv];
            if(!a[nv] || !b[nv]){
                que.push(nv);
                ok[nv]=false;
            }
        }
    }
    rep(i, n)if(ok[i]){
        printf("Yes\n");
        return 0;
    }
    printf("No\n");
}
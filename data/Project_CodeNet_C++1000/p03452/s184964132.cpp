#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = INT_MAX;
const ll INF = 1e18;
const ld EPS = 1e-10;

const int MAX_V = 1e5;
vector<pii> es[MAX_V];
int pos[MAX_V];
bool used[MAX_V], able;

void dfs(int now){
    used[now] = true;
    for(auto &e: es[now]){
        int to = e.first, d = e.second;
        if(pos[to] == inf){
            pos[to] = pos[now]+d;
            dfs(to);
        }
        else if(pos[to] != pos[now]+d) able = false;
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    rep(i, M){
        int L, R, D;
        cin >> L >> R >> D;
        L--, R--;
        es[L].pb(pii(R, D));
        es[R].pb(pii(L, -D));
    }
    fill(used, used+N, false);
    fill(pos, pos+N, inf);
    able = true;
    rep(i, N){
        if(!used[i]) pos[i] = 0, dfs(i);
    }
    if(able) cout << "Yes" << endl;
    else cout << "No" << endl;
}
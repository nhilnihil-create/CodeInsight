#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

const int MAX = 2e5;
set<int> s[MAX];
int H, W;
int ans = inf;

void dfs(int x, int y, int flag){
    chmin(ans, *s[y].upper_bound(x));
    if(flag && y != W-1 && !s[y+1].count(x)) dfs(x, y+1, 0);
    elif(x != H-1 && !s[y].count(x)) dfs(x+1, y, 1);
}

int main(){
    int N;
    cin >> H >> W >> N;
    rep(i, N){
        int X, Y; cin >> X >> Y; X--, Y--;
        s[Y].insert(X);
    }
    rep(i, MAX) s[i].insert(H);
    dfs(0, 0, 0);
    cout << ans << endl;
}
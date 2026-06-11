#pragma region header
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rev(i, n) for(int i = (int)(n - 1); i >= 0; i--)
#define rev1(i, n) for(int i = (int)(n); i > 0; i--)
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define resort(v) sort((v).rbegin(), (v).rend())
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
using ll = long long;
using P = pair<int, int>;
/* ----------------よく使う数字や配列----------------- */
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
constexpr ll mod = 1e9+7;
constexpr int inf = INT32_MAX/2;
constexpr ll INF = LLONG_MAX/2;
constexpr long double eps = DBL_EPSILON;
constexpr long double pi = 3.141592653589793238462643383279;
/* ----------------------end----------------------- */

/* --------------------テンプレート------------------ */
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
/* ----------------------end----------------------- */

/* --------------------ライブラリ-------------------- */
ll fact(int i) {       //階乗
    if (i == 0) return 1;
    return (fact(i - 1)) * i % mod;
}
ll gcd(ll a, ll b) {        //最大公約数
    if(b == 0) return a;
    return gcd(b, a % b); 
}
ll lcm(ll a, ll b) {      //最小公倍数
    return a / gcd(a, b) * b ;
}
int keta(ll n) {        //桁数を求める
    if(n == 0) return 1;
    int count = 0;
    while(n != 0) {
        n /= 10;
        count++;
    }
    return count;
}
ll ketasum(ll n) {    //各桁の和
    ll sum = 0;
    while(n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
/* ----------------------end----------------------- */
#pragma endregion
struct edge{int to,cost;};
vector<vector<edge>> G(100100);
vi dist(100100,inf);
bool bfs(int s) {
    queue<int> que;
    que.push(s);
    dist[s]=0;
    while(!que.empty()) {
        int v = que.front();que.pop();
        for(auto e:G[v]) {
            // cout << v+1 << ' ' << e.to+1 << ' ' << dist[e.to] << ' ' << dist[v]+e.cost << endl;
            if(dist[e.to]!=inf&&dist[e.to]!=dist[v]+e.cost) {
                // cout << v+1 << ' ' << e.to+1 << ' ' << dist[e.to] << ' ' << dist[v]+e.cost << endl;
                return true;
            }
            if(dist[e.to]==inf) {
                dist[e.to]=dist[v]+e.cost;
                que.push(e.to);
            }
        }
    }
    return false;
}
signed main() {
    int n,m;cin >> n >> m;
    if(m==0) {
        printf("Yes\n");
        return 0;
    }
    rep(i, m) {
        int a,b,cost;cin >> a >> b >> cost;
        a--;b--;
        G[a].pb({b,cost});
        G[b].pb({a,-cost});
    }
    rep(i, n) {
        if(dist[i]==inf) {
            if(bfs(i)) {
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
    // rep(i, 3) cout << dist[i] << ' ' << char(10);
    return 0;
}
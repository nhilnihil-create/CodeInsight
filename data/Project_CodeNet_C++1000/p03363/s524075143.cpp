/////////////////////////////////////////////////
/////             Give me AC!!!!            /////
/////////////////////////////////////////////////
//↑これじゃ気合いが足りない！
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////             お願いしますACをくださいそうじゃないと僕泣きますお願いしますACをくださいJudge様....            /////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,N) for(int i = 0; i < (N); i++)
#define erep(i,N) for(int i = N - 1; i >= 0; i--)
const int MOD = 1000000007;
const int MAX = 100000;
const ld PI = (acos(-1));
using Graph = vector<vector<int>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}
typedef pair<int, int> P;
typedef pair<ll,ll> PLL;
ld rad(ld a) {return a * 180 / PI;}
const int dx[4] = {1, 0, -1, 0};//2次元グリッド上のx軸方向
const int dy[4] = {0, 1, 0, -1};//2次元グリッド上のy軸方向

struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};

map<ll,ll> factorize_list;

void prime_factorize(ll N) {
    for (ll a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        ll ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        factorize_list[a] = ex;
    }

    // 最後に残った数について
    if (N != 1) factorize_list[N] = 1;
    return ;
}

//dpTable
vector<ll> dp(100,MAX);

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll mod(ll val, ll m) {
  ll res = val % m;
  if (res < 0) res += m;
  return res;
}

long long fac[MAX], finv[MAX], inv[MAX];

char upper(char c){
    if('a' <= c && c <= 'z'){
        c = c - ('a' - 'A');
    }
    return c;
}
char lower(char c){
    if('A' <= c && c <= 'Z'){
        c = c + ('a' - 'A');
    }
    return c;
}

const ll INF = 10000000000;
struct edge{ll to, cost;};

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    ll sum = 0;
    map<ll,ll> mp;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        sum += a;
        mp[sum]++;
    }
    ll ans = 0;
    for (auto p : mp) {
        if (p.first == 0) ans += p.second;
        ans += p.second * (p.second - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}

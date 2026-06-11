#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(i) begin(i), end(i)

const int INF = 0x3fffffff;
const ll MINF = 0x7fffffffffff;
const ld DINF = numeric_limits<ld>::infinity();
const int MOD = 1000000007;
const int MODD = 998244353;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932;

template<class T> bool chmin(T &a, const T &b){ if(a > b){ a = b; return 1; } else return 0; }
template<class T> bool chmax(T &a, const T &b){ if(a < b){ a = b; return 1; } else return 0; }
template<class T> auto min(const T& a){ return *min_element(all(a)); }
template<class T> auto max(const T& a){ return *max_element(all(a)); }

ll gcd(ll a, ll b){ while(b){ ll c = b; b = a % b; a = c; } return a; }
ll lcm(ll a, ll b){ if(!a || !b) return 0; return a * b / gcd(a, b); }
ll pow_mod(ll n,ll k,ll m){ll r = 1;for(; k > 0;k >>= 1) {if (k & 1) r = (r * n) % m; n = (n * n) % m;}return r;}

//ここから。
int main(){
    int H,W;
    cin >> H >> W;
    vector<vector<int>> c(10,vector<int> (10));
    rep(i,10)
        rep(j,10) cin >> c[i][j];
    
    vector<vector<int>> A(H,vector<int> (W));
    rep(i,H)
        rep(j,W) cin >> A[i][j];

    rep(k,10)
        rep(i,10)
            rep(j,10) chmin(c[i][j],c[i][k] + c[k][j]);
    
    ll cost = 0;
    rep(i,H){
        rep(j,W){
            if(A[i][j] == -1) continue;
            if(A[i][j] == 1) continue;
            cost += c[A[i][j]][1];
        }
    }
    cout << cost << endl;
}
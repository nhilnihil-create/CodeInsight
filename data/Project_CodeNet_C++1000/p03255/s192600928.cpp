#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define rep2(i, x, n) for(ll i = x; i <= n; i++)
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
const int inf = 1e9+3;
const ll INF = 1e18+3;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    ll N, X;
    cin >> N >> X;
    ll x[N], ans = INF;
    rep(i, N) cin >> x[i];
    ll sum[N+1];
    sum[0] = 0;
    rep(i, N) sum[i+1] = sum[i]+x[i];
    //i回ゴミ箱に戻ってくる場合
    rep2(i, 1, N){
        ll tmp = (N+i)*X+5*sum[N];
        for(ll j = N-2*i; j >= 0; j -= i){
            tmp += 2*sum[j];
            if(tmp > ans) break;
        }
        chmin(ans, tmp);
    }
    cout << ans << endl;
}
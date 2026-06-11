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

int main(){
    int N;
    cin >> N;
    int b[N], memo[N];
    rep(i, N) cin >> b[i];
    rep(i, N) memo[i] = b[i];
    rep(i, N){
        if(b[i] > i+1) {cout << -1 << endl; return 0;}
    }
    vector<int> ans;
    rep(i, N){
        rep3(j, N-1, 0){
            if(b[j] == j+1){
                ans.pb(memo[j]);
                b[j] = 0;
                rep2(k, j+1, N-1) b[k]++;
                break;
            }
        }
    }
    rep3(i, N-1, 0) cout << ans[i] << endl;
}
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
    int H, W, N;
    cin >> H >> W >> N;
    int sx, sy;
    cin >> sx >> sy;
    string S, T;
    cin >> S >> T;
    int l = 0, r = W+1, u = 0, d = H+1;
    rep3(i, N-1, 0){
        if(T[i] == 'L') if(r != 1) r = min(r+1, W+1);
        if(T[i] == 'R') if(l != W) l = max(l-1, 0);
        if(T[i] == 'U') if(d != 1) d = min(d+1, H+1);
        if(T[i] == 'D') if(u != H) u = max(u-1, 0);
        if(S[i] == 'L') l = min(l+1, W);
        if(S[i] == 'R') r = max(r-1, 1);
        if(S[i] == 'U') u = min(u+1, H);
        if(S[i] == 'D') d = max(d-1, 1);
    }
    if(l < sy && sy < r && u < sx && sx < d) cout << "YES" << endl;
    else cout << "NO" << endl;
}
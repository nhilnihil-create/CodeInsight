#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(), x.end()
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const ll inf = 1e18;
const int MAX_N = 500;

int main() {
    int n, m; cin >> n >> m;
    vvll x(n,vll(3));
    rep(i,n)rep(j,3) cin >> x[i][j];
    ll ans = -inf;
    rep(i,1<<3) {
        vll tmp(n,0);
        rep(j,n) {
            rep(k,3) {
                if (i>>k&1) tmp[j] += -x[j][k];
                else tmp[j] += x[j][k];
            }
        }
        sort(tmp.rbegin(),tmp.rend());
        ll sum = 0;
        rep(j,m) sum += tmp[j];
        ans = max(ans,sum);
    }
    cout << ans << endl;
}
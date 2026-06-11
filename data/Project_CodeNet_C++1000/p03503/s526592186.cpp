#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

int main() {
    int n; cin >> n;
    vvint f(n,vint(10)), p(n,vint(11));
    rep(i,n)rep(j,10) cin >> f[i][j];
    rep(i,n)rep(j,11) cin >> p[i][j];
    int ans = -inf;
    REP(i,1<<10) {
        int sum = 0;
        rep(j,n) {
            int ct = 0;
            rep(k,10) {
                if ((i>>k & 1) && f[j][k]) ct++;
            }
            sum += p[j][ct];
        }
        ans = max(ans,sum);
    }
    cout << ans << endl;
}
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
const int inf = 1e9;
const int MAX = 100005;

int main() {
    int n, c; cin >> n >> c;
    vvint d(c,vint(c));
    vvint x(3);
    rep(i,c)rep(j,c) cin >> d[i][j];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int a; cin >> a;
            x[(i+j)%3].push_back(a);
        }
    }
    vvint y(3,vint(c));
    for (int color = 0; color < c; color++) {
        rep(i,3) {
            int sum = 0;
            rep(j,x[i].size()) {
                sum += d[x[i][j]-1][color];
            }
            y[i][color] = sum;
        }
    }
    int ans = inf;
    rep(i,c) {
        rep(j,c) {
            if (i == j) continue;
            rep(k,c) {
                if (k == j || k == i) continue;
                ans = min(ans,y[0][i]+y[1][j]+y[2][k]);
            }
        }
    }
    cout << ans << endl;
}
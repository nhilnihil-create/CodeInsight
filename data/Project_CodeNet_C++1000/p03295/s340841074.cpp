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
const int mod = 1e5;
const int MAX = 1e5+5;

int main() {
    int n, m; cin >> n >> m;
    vector<P> q(m);
    rep(i,m) {
        int a, b; cin >> a >> b;
        a--; b--;
        q[i].first = b; q[i].second = a;
    }
    int ans = 0;
    vector<bool> check(m,true);
    while (true) {
        bool ok = false;
        rep(i,m) if (check[i]) ok = true;
        if (!ok) break;
        vector<P> x;
        rep(i,m) if (check[i]) x.push_back(q[i]);
        sort(all(x));
        rep(i,m) if (q[i].second <= x[0].first-1) check[i] = false;
        ans++;
    }
    cout << ans << endl;
}
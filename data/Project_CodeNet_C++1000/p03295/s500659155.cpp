#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) REP(i, 0, n)
#define rrep(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define sz(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define INF 2e9
#define LINF 1e18
#define mod 1000000007
template<class T> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> P;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main() {
    int n,m; cin >> n >> m;
    vector<P> p(m);
    int a,b;
    rep(i,m) {
        cin >> a >> b;
        p[i].first = b;
        p[i].second = a;
    }
    sort(all(p));
    int ans = 0;
    int t = 0;
    rep(i,m) {
        if (t <= p[i].second) {
            ans++;
            t = p[i].first;
        }
    }
    cout << ans << endl;
}
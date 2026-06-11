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
    int n; cin >> n;
    vector<P> r(n), b(n);
    int x, y;
    rep(i,n) {
        cin >> x >> y;
        r[i].first = x;
        r[i].second = y;
    }
    rep(i,n) {
        cin >> x >> y;
        b[i].first = x;
        b[i].second = y;
    }

    sort(all(r));
    sort(all(b));

    int ans = 0;

    rep(i,n) { //blueの点のループ
        int k = 0;
        rep(j,n) { //red
            if (r[j].first >= b[i].first) break;
            k++;
        }
        int y_mx = -1; int bangou;
        bool exist = false;
        rep(j,k) { //y座標maxをとる
            if (r[j].second < b[i].second) {
                exist = true;
                if (y_mx < r[j].second) {
                    y_mx = r[j].second;
                    bangou = j;
                }
            }
        }
        if (exist) {
            ans++;
            r[bangou].first = 1000; //採用した点の実質削除
            sort(all(r));
        }
    }

    cout << ans << endl;
}
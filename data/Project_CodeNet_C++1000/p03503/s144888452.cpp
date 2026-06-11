#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()


int main() {
    int n;
    cin >> n;
    vector<int> fs;
    rep (i, n) {
        int f = 0;
        rep (j, 10) {
            int g;
            cin >> g;
            f += (g << j);
        }
        fs.push_back(f);
    }
    vector<vector<int>> profit(n, vector<int>(11));
    rep (i, n) {
        rep (j, 11) {
            cin >> profit[i][j];
        }
    }
    int ans = -1e9;
    rep (i, 1, (1<<10)) {
        int x = 0;
        rep (j, n) {
            int p = fs[j] & i;
            int ctr = 0;
            rep (k, 10) {
                if (p % 2) {
                    ctr++;
                }
                p /= 2;
            }
            x += profit[j][ctr];
        }
        chmax(ans, x);
    }
    cout << ans << endl;
}
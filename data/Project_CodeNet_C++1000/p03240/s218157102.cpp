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
    vector<int> x(n), y(n), h(n);
    int base;
    rep (i, n) {
        cin >> x[i] >> y[i] >> h[i];
        if (h[i] != 0) {
            base = i;
        }
    }
    rep (cx, 101) {
        rep (cy, 101) {
            int H = abs(cx - x[base]) + abs(cy - y[base]) + h[base];
            rep (i, n) {
                if (max(H - abs(cx - x[i]) - abs(cy - y[i]), 0) != h[i]) {
                    break;
                } else if (i == n - 1) {
                    printf("%d %d %d\n", cx, cy, H);
                    exit(0);
                }
            }
        }
    }
}
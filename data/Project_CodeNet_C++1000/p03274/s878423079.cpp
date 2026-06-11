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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep (i, n) {
        cin >> a[i];
    }
    int ans = 1e9 + 7;
    rep (i, n - k + 1) {
        int l = a[i];
        int r = a[i + k - 1];
        if (1ll * l * r < 0) {
            int res = min(abs(l) * 2 + abs(r), abs(r) * 2 + abs(l));
            chmin(ans, res);
        } else {
            int res = max(abs(l), abs(r));
            chmin(ans, res);
        }
    }
    cout << ans << endl;
}
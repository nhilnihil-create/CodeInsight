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
    vector<int> c(n-1), s(n-1), f(n-1);
    rep (i, n-1) {
        cin >> c[i] >> s[i] >> f[i];
    }
    rep (i, n) {
        int t = 0;
        rep (j, i, n-1) {
            if (t <s[j]) {
                t = s[j] + c[j];
            } else {
                t = ceil(1.0 * t / f[j]) * f[j] + c[j];
            }
        }
        cout << t << endl;
    }
}

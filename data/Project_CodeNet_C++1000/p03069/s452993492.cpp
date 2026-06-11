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
    string s;
    cin >> s;
    vector<int> b(n+1, 0), w(n+1, 0);
    rep (i, n) {
        if (s[i] == '#') {
            b[i+1]++;
        } else {
            w[i+1]++;
        }
        b[i+1] += b[i];
        w[i+1] += w[i];
    }
    int ans = 1e9 + 7;
    rep (i, n + 1) {
        chmin(ans, b[i] + w[n] - w[i]);
    }
    cout << ans << endl;

}
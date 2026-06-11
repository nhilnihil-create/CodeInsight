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
    string s;
    cin >> s;
    string t;
    rep (i, s.size()) {
        if (s[i] == 'x') {
            continue;
        } else {
            t += s[i];
        }
    }

    rep (i, (t.size() + 1) / 2) {
        if (t[i] != t[t.size() - 1 - i]) {
            cout << -1 << endl;
            exit(0);
        }
    }

    vector<int> xs(t.size() + 1, 0);
    int sidx = 0;
    rep (i, t.size()) {
        int ctr = 0;
        while (s[sidx] == 'x') {
            ctr++;
            sidx++;
        }
        xs[i] = ctr;
        sidx++;
    }
    sidx--;
    xs[t.size()] = s.size() - 1 - sidx;
    int ans = 0;
    rep (i, (xs.size() + 1) / 2) {
        ans += abs(xs[i] - xs[xs.size() - 1 - i]);
    }
    cout << ans << endl;
}
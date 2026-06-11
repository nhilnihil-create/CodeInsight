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
    int ab, a, b, ba;
    ab = a = b = ba = 0;
    rep (i, n) {
        string s;
        cin >> s;
        rep(i, s.size() - 1) {
            if (s[i] == 'A' && s[i+1] == 'B') {
                ab++;
            }
        }
        if (s[0] == 'B' && s[s.size() - 1] == 'A') {
            ba++;
        } else if (s[0] == 'B') {
            b++;
        } else if (s[s.size() - 1] == 'A') {
            a++;
        }
    }
    int ans = ab;
    ans += max(ba - 1, 0);
    if (a > 0 && ba > 0) {
        ans++;
        a--;
    }
    if (b > 0 && ba > 0) {
        ans++;
        b--;
    }
    ans += min(a, b);
    cout << ans << endl;
}

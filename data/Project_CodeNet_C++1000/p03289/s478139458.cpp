#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
typedef long long ll;
typedef long double ld;
const long long INF = 1e18;
# define len(x) ((int)(x).size())
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define foreps(i, m, n) for(int i = m;i < n;i++)
# define ALL(x) (x).begin(), (x).end()
# define rall(x) (x).rbegin(), (x).rend()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    string S; cin >> S;
    string ans = "AC";

    if (S.at(0) != 'A') ans = "WA";

    ll cnt = 0;
    for (int i = 1; i < len(S); i++) {
        if (isupper(S.at(i))) {
            if (i == 1 || i == len(S) - 1 || S.at(i) != 'C') {
                ans = "WA";
            }
            cnt++;
        }
    }
    if (cnt != 1) ans = "WA";
    cout << ans << endl;
}
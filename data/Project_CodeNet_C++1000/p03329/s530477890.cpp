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
    vector<int> six, nine;
    six.push_back(6);
    nine.push_back(9);
    while(six.back() < 100000) {
        six.push_back(six.back() * 6);
    }
    while(nine.back() < 100000) {
        nine.push_back(nine.back() * 9);
    }
    vector<int> dp(n+1, 1e9+7);
    dp[0] = 0;
    rep (i, 1, n+1) {
        dp[i] = dp[i-1] + 1;
        rep (j, six.size()) {
            if (i >= six[j]) {
                chmin(dp[i], dp[i -six[j]] + 1);
            } else {
                break;
            }
        }
        rep (j, nine.size()) {
            if (i >= nine[j]) {
                chmin(dp[i], dp[i - nine[j]] + 1);
            } else {
                break;
            }
        }
    }
    cout << dp[n] << endl;
}
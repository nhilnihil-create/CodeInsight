#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <string>
#define _repargs(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _repargs(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define inf 2000000007
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
template <typename T>
inline void output(T a, int p = 0) {
    if(p) cout << fixed << setprecision(p)  << a << "\n";
    else cout << a << "\n";
}
// end of template

pair<int, int> update(pair<int, int> a, pair<int, int> b) {
    if(a.first > b.first) {
        return mp(a.first, max(a.second, b.first));
    }
    else {
        return mp(b.first, max(a.first, b.second));
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // source code
    int N;
    cin >> N;
    vector<int> A(1 << N);
    vector<pair<int, int>> dp(1 << N); // first > second
    rep(i, 1 << N) {
        cin >> A[i];
        dp[i] = mp(A[i], 0);
    }
    
    rep(j, N) {
        rep(i, 1 << N) {
            if(i & (1 << j)) {
                dp[i] = update(dp[i], dp[i ^ (1 << j)]);
            }
        }
    }
    
    int cur = 0;
    rep(i, 1, 1 << N) {
        cur = max(cur, dp[i].first + dp[i].second);
        output(cur);
    }
    
    
    return 0;
}

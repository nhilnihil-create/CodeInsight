#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const ll INF = 1<<21;
// static const ll MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    llint n, k;
    cin >> n >> k;

    llint ans = 0, p, r;
    for(llint ib=1;ib<=n;ib++) {
        p = n/ib;
        r = n%ib;
        ans += p*max(0LL, ib-k);
        ans += max(0LL, r-k+1);
    }

    if(k==0) ans -= n;

    cout << ans << endl;
    return 0;
}

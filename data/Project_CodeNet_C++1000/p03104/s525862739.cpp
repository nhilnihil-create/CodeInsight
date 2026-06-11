#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()
#define endl "\n"

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
typedef long long ll;

ll f(ll x) {
    if (x%2 == 0) {
        return x ^ (((x/2)%2 == 0) ? 0 : 1);
    } else return (((x+1)/2)%2 == 0) ? 0 : 1;
}

void solve() {
    ll A,B;
    cin >> A >> B;
    A = max(0LL,A-1);
    cout << (f(A)^f(B)) << endl;

}

int main() {
    solve();
    return 0;
}
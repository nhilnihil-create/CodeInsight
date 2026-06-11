#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    ll D, N;
    cin >> D >> N;
    ll ans = 1;
    rep(i,D) ans *= 100LL;
    if (N == 100) ++N;
    ans *= N;
    cout << ans << endl;
}

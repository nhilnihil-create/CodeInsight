#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
typedef long long ll;

int main ()
{
    ll N; cin >> N;

    set<ll> cnd;
    for (ll i = 1LL; i <= N; i *= 6) {
        cnd.insert(i);
    }
    for (ll i = 1LL; i <= N; i *= 9) {
        cnd.insert(i);
    }

    vector<ll> dp(100010, 1e18);
    dp[0] = 0;

    vector<ll> anst;
    for (auto x: cnd) {
        for (int i = 0; i + x <= 100005; i++) {
            dp[i + x] = min(dp[i + x], dp[i] + 1);
        }
    }

    cout << dp[N] << endl;

    return 0;
}

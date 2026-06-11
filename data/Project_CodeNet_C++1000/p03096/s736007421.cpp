#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <cmath>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;

const int MOD = 1000000007;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<ll> C(N);
    Rep (i, N) {
        cin >> C[i];
    }

    vec pre(2e5+1, -1);
    vec check(N, -1);
    Rep (i, N) {
        check[i] = pre[C[i]];
        pre[C[i]] = i;
    }

    // Rep (i, N) {
    //     cout << check[i] << " ";
    // }
    // cout << "\n";

    vec dp(N+1);
    dp[0] = 1;
    Rep (i, N) {
        dp[i+1] = dp[i];
        ll j = check[i];
        if (j == i-1) {
            continue;
        }
        if (j != -1) {
            dp[i+1] += dp[j+1];
            dp[i+1] %= MOD;
        }
    }

    cout << dp[N] << "\n";
}
#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;
ll const MAX_N = 510000;
ll const MOD = 1000000007;

int main() {
    string S;
    cin >> S;

    ll o_cnt = 0;
    ll x_cnt = 0;
    rep(i, S.length()) {
        if (S[i] == 'o')
            o_cnt++;
        else if (S[i] == 'x')
            x_cnt++;
    }

    ll res = 15 - S.length();

    if (res + o_cnt >= 8) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

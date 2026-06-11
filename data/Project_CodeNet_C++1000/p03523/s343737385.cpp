#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
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

    string S_copy = S;

    size_t c;
    while ((c = S_copy.find_first_of("A")) != string::npos) {
        S_copy.erase(c, 1);
    }

    if (S_copy != "KIHBR") {
        cout << "NO" << endl;
        return 0;
    }

    vector<ll> A_cnt(6, 0);
    ll idx = 0;
    rep(i, S.length()) {
        if (S[i] == 'A') {
            A_cnt[idx]++;
        } else {
            idx++;
        }
    }

    vector<ll> A_ans = {1, 0, 0, 1, 1, 1};

    rep(i, 6) {
        if (A_cnt[i] > A_ans[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}

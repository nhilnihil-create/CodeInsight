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
    string S_in, T;
    cin >> S_in >> T;

    vector<ll> idx;

    rep(i, S_in.length() - T.length() + 1) {
        bool is_s = true;
        rep(j, T.length()) {
            if (S_in[i + j] == '?') continue;

            if (S_in[i + j] != T[j]) {
                is_s = false;
                break;
            }
        }
        if (is_s) {
            idx.push_back(i);
        }
    }

    if (idx.size() == 0) {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    rep(i, S_in.length()) {
        if (S_in[i] == '?') S_in[i] = 'a';
    }

    vector<string> S_cand;
    repv(idx) {
        ll i = *it;
        string S = S_in;

        rep(j, T.length()) { S[i + j] = T[j]; }
        S_cand.push_back(S);
    }

    sort(S_cand.begin(), S_cand.end());

    cout << S_cand[0] << endl;

    return 0;
}

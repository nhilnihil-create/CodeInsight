#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <functional>
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
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define INIT    \
    cin.tie(0); \
    ios::sync_with_stdio(false);

template <class T>
inline bool chmax(T& a, T b) {
    return a = (a < b) ? b : a;
}
template <class T>
inline bool chmin(T& a, T b) {
    return a = (a > b) ? b : a;
}

ll const INF = 1LL << 60;
ll const MOD = 1000000007;

typedef pair<ll, ll> P;

bool compare_by_b(P a, P b) {
    if (a.second != b.second) {
        return a.second > b.second;
    } else {
        return a.first < b.first;
    }
}

int main() {
    INIT;
    ll N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    vector<ll> nums;
    if (S[0] == '0') nums.pb(0);

    ll cnt = 0;
    rep(i, SZ(S)) {
        if (i == 0) {
            cnt++;
        } else {
            if (S[i - 1] != S[i]) {
                nums.pb(cnt);
                cnt = 1;
            } else {
                cnt++;
            }
        }

        if (i == SZ(S) - 1) {
            nums.pb(cnt);
        }
    }

    // repv(nums) cout << *it << " ";
    // cout << endl;

    ll right = 0;
    ll sum = 0;
    ll res = 0;
    for (ll left = 0; left < SZ(nums); left += 2) {
        while (right < SZ(nums) && (right - left + 1) <= 2 * K + 1) {
            sum += nums[right];
            right++;
        }

        chmax(res, sum);

        if (right == left)
            right += 2;
        else {
            sum -= nums[left];
            sum -= nums[left + 1];
        }
    }

    cout << res << endl;
}
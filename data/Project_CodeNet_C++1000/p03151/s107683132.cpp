#include <algorithm>
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
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    rep(i, N) { cin >> A[i]; }
    rep(i, N) { cin >> B[i]; }

    ll sumA = 0;
    ll sumB = 0;
    rep(i, N) {
        sumA += A[i];
        sumB += B[i];
    }

    if (sumA < sumB) {
        cout << "-1" << endl;
        return 0;
    }

    vector<ll> D(N);
    rep(i, N) { D[i] = A[i] - B[i]; }

    sort(D.begin(), D.end(), greater<ll>());

    ll cnt = 0;
    ll diff = 0;
    for (ll i = N - 1; i >= 0; i--) {
        if (D[i] < 0) {
            diff += D[i];
            cnt++;
        } else {
            break;
        }
    }

    // cout << "diff:" << diff << endl;
    // cout << "cnt:" << cnt << endl;

    for (ll i = 0; i < N; i++) {
        if (D[i] > 0 && diff < 0) {
            diff += D[i];
            cnt++;
        } else {
            break;
        }
    }

    cout << cnt << endl;

    return 0;
}
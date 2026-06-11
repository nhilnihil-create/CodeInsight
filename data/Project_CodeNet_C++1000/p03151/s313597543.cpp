#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    vector<ll> diff;
    ll a_sum = 0;
    ll b_sum = 0;
    bool judge = 1;
    rep(i, N) { cin >> A[i]; }

    rep(i, N) { cin >> B[i]; }

    rep(i, N) {
        a_sum += A[i];
        b_sum += B[i];
        if (A[i] < B[i])
            judge = 0;
        if (A[i] >= B[i])
            diff.push_back(A[i] - B[i]);
    }

    if (judge) {
        cout << 0 << endl;
        return 0;
    }
    ll diff_sum = a_sum - b_sum;
    if (a_sum - b_sum < 0) {
        cout << -1 << endl;
        return 0;
    }
    ll res = 0;
    sort(diff.begin(), diff.end());
    rep(i, diff.size()) {
        if (diff_sum - diff[i] >= 0)
            diff_sum -= diff[i], res++;
    }

    res = N - res;
    cout << res << endl;
    return 0;
}
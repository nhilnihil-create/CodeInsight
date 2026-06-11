#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    rep(i, N) { cin >> A[i]; }

    rep(i, N) { cin >> B[i]; }

    ll diff_sum = 0;
    ll diff_b = 0, diff_a = 0;
    rep(i, N) {
        diff_sum += (B[i] - A[i]);
        if (B[i] > A[i])
            diff_b += (B[i] - A[i]) / 2;
        else
            diff_a += (A[i] - B[i]);
    }

    if (diff_sum < 0) {
        cout << "No" << endl;
        return 0;
    }

    if (diff_b >= diff_a) {
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
    return 0;
}
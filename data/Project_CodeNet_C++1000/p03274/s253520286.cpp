#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> A(N);

    rep(i, N) { cin >> A[i]; }

    ll res = INF;
    for (int i = 0; i + K - 1 < N; i++) {
        ll left = A[i], right = A[i + K - 1];
        res = min(res, min(abs(left), abs(right)) + right - left);
    }

    cout << res << endl;
}
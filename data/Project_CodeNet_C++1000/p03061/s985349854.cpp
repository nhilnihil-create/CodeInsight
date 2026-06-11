#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

long long GCD(long long a, long long b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) { cin >> A[i]; }
    vector<ll> left(N), right(N);
    ll lgcd = A[0];
    for (int i = 0; i < N; i++) {
        lgcd = GCD(lgcd, A[i]);
        left[i] = lgcd;
    }

    ll rgcd = A[N - 1];

    for (int i = N - 1; i > -1; i--) {
        rgcd = GCD(rgcd, A[i]);
        right[i] = rgcd;
    }

    int lcur = 0, rcur = 2;
    ll ans = 1;
    ans = max(ans, max(right[1], left[N - 2]));
    while (rcur <= N - 1) {
        ans = max(ans, GCD(left[lcur], right[rcur]));
        lcur++;
        rcur++;
    }

    cout << ans << endl;
}
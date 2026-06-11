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
    rep(i, N) {
        cin >> A[i];
        A[i] -= (i + 1);
    }

    sort(all(A));

    ll mid = 0, res = 0;
    if (N % 2 == 0)
        mid = (A[N / 2] + A[N / 2 - 1]) / 2;
    else
        mid = A[N / 2];

    rep(i, N) { res += abs(A[i] - mid); }

    cout << res << endl;
}
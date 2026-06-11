#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N;
vector<ll> A;
int main() {
    cin >> N;
    A.resize(N + 2);
    rep(i, N) cin >> A[i + 1];

    ll total = 0;
    for (int i = 1; i < N + 2; i++) {
        total += abs(A[i] - A[i - 1]);
    }

    for (int i = 1; i <= N; i++) {
        ll connect = abs(A[i - 1] - A[i + 1]);
        ll minus = abs(A[i] - A[i - 1]) + abs(A[i] - A[i + 1]);

        cout << total + connect - minus << endl;
    }
    // cout << total << endl;
}
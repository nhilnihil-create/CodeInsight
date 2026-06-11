// 8/7過去問
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;

    vector<int> A(N+2);
    A[0] = 0;
    rep(i, N) {
        cin >> A[i+1];
    }
    A[N+1] = 0;

    vector<int> S(N+2);
    S[0] = 0;
    rep(i, N + 1) {
        S[i+1] = S[i] + abs(A[i+1] - A[i]);
    }

    int ans = 0;

    rep(i, N) {
        cout << S[N+1] - (S[i+2] - S[i]) + abs(A[i+2] - A[i]) << endl;
    }

}

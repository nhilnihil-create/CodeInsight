#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N + 2);
    A[0] = 0;
    FOR(i, 1, N + 1) cin >> A[i];
    A[N + 1] = 0;
    int all = 0;
    rep(i, N + 1) {
        all += abs(A[i] - A[i + 1]);
    }
    FOR(i, 1, N + 1) {
        cout << all - abs(A[i] - A[i - 1]) - abs(A[i] - A[i + 1]) + abs(A[i - 1] - A[i + 1]) << endl;
    }
    return 0;
}
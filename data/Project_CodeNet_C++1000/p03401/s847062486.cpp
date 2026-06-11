#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int N;
    cin >> N;
    vec<int> A(N + 2);
    A[0]     = 0;
    A[N + 1] = 0;
    rep(i, N) cin >> A[i + 1];
    ll sum = 0;
    for (int i = 1; i <= N + 1; ++i) {
        sum += abs(A[i] - A[i - 1]);
    }
    for (int i = 1; i <= N; ++i) {
        if (A[i] >= A[i - 1] && A[i + 1] >= A[i]) {
            cout << sum << endl;
        } else if (A[i - 1] >= A[i] && A[i] >= A[i + 1]) {
            cout << sum << endl;
        } else {
            int dec = abs(A[i - 1] - A[i]) + abs(A[i] - A[i + 1]);
            int pul = abs(A[i - 1] - A[i + 1]);
            cout << sum - dec + pul << endl;
        } 
    }
}

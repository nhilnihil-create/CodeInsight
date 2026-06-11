// 7/13
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int min_value = 1e9;
    rep(i, N) if (A[i] < min_value) min_value = A[i];

    // vector<int> P;
    // P.push_back(-1);
    // rep(i, N) if (A[i] == min_value) P.push_back(i);
    // P.push_back(N);

    // int l = P.size();
    // int res = 0;
    // rep(i, l-1) {
    //     int step = K - 1;
    //     int dist = P[i+1] - P[i] - 1;
    //     res += (dist + step - 1) / step;
    // }

    // int res = 0;
    // int i = 0;
    // while (i < N) {
    //     if (A[i] != min_value) {
    //         res += 1;
    //         i += (K - 1);
    //     } else {
    //         i += 1;
    //     }
    // }

    // cout << res << endl;

    cout << ((N-1) + (K-1) - 1) / (K-1) << endl;
}
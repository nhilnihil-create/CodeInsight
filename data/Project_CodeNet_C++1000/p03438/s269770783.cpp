#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//==================================

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    Vl A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    ll sum1 = 0, sum2 = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] > B[i])
            sum1 += A[i] - B[i];
        else
            sum2 += (B[i] - A[i]) / 2;
    }

    cout << (sum2 >= sum1 ? "Yes" : "No") << "\n";

    return 0;
}
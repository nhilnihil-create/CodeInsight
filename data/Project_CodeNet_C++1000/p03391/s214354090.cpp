#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 先攻はA[i] > B[i]のものを1つだけ残して他を全部0にするのが最適

int main() {
    int N;
    cin >> N;
    vector<int>A(N);
    vector<int>B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }
    int k = INT_MAX;
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] > B[i]) k = min(k, B[i]);
        ans += A[i];
    }
    if (k != INT_MAX) ans -= k;
    else ans = 0;
    cout << ans << "\n";
    return 0;
}
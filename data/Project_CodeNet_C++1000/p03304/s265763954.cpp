#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    int N, M, D;
    cin >> N >> M >> D;

    double ans = 1.0 * (N - D) / N / N * (M - 1);
    if (D != 0) {
        ans *= 2;
    }
    cout << setprecision(10) << ans << endl;
}

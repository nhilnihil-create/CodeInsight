#include <bits/stdc++.h>
using namespace std;
// stock = A; loop { buy B; if stock <= C then add D }
int solve(long long A, long long B, long long C, long long D)
{
    if (D < B) return 0;
    if (A < B) return 0;
    if (C >= B) return 1;
    A %= B;
    D %= B;
    if (A > C) return 0;
    if (D == 0) return 1;
    long long E = __gcd(B, D);
    // C < A + kE < B となる k が存在すれば終了する
    long long k = (C - A) / E + 1;
    return A + k * E >= B;
}
int main()
{
    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        long long A, B, C, D;
        cin >> A >> B >> C >> D;
        int ans = solve(A, B, C, D);
        cout << (ans == 1 ? "Yes" : ans == 0 ? "No" : to_string(ans)) << '\n';
    }
    return 0;
}
#include <iostream>
using namespace std;
constexpr int M = 1000000007;

int main() {
    int n; cin >> n;
    long long C[n];
    long long pl[n+1], pr[n+2], g[n+1], c[n+1];
    pl[0] = 1; pr[n+1] = 1;
    for (int i = 1; i <= n; i++) pl[i] = pl[i-1] * i % M;
    for (int i = n; i > 0; i--) pr[i] = pr[i+1] * i % M;
    for (int i = 1; i <= n; i++) g[i] = pl[i-1] * pr[i+1] % M;
    c[1] = 0;
    for (int i = 1; i <= n; i++) c[1] += g[i];
    c[1] %= M;
    for (int i = 2; i <= n; i++) c[i] = (c[i-1] + g[i] - g[n-i+2]) % M;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      long long a; cin >> a;
      ans += a * c[i] % M;
    }
    cout << (ans % M + M) % M << endl;
}

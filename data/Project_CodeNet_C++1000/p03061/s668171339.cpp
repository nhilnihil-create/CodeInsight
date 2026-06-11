#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
using ll = long long;
int a[100001];
int x[100001];
int y[100001];
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int N;
    cin >> N;
    rep(i, N) cin >> a[i];
    x[0] = a[0];
    rep2(i, N - 1) {
        x[i] = gcd(x[i - 1], a[i]);
    }
    y[N-1] = a[N-1];
    for (int i = N-2; i >= 0; --i) {
        y[i] = gcd(y[i + 1], a[i]);
    }
    int ans = 0;
    for (int i = 1; i < N-1; i++) {
        ans = max(ans, gcd(x[i - 1], y[i + 1]));
    }
    ans = max(ans, y[1]);
    ans = max(ans, x[N-2]);
    cout << ans << endl;
}
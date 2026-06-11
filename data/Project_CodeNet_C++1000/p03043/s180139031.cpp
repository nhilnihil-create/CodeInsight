#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    double N, K;
    cin >> N >> K;

    double ans = 0;
    for (double i = 1; i <= N; ++i) {
        if (i >= K) {
            ans += 1.0;
        } else {
            ans += pow(0.5, ceil(log2(K / i)));
        }
    }
    ans = ans / N;
    cout << fixed << setprecision(12) << ans << endl;
}

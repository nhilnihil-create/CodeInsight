#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
    int K, A, B;
    cin >> K >> A >> B;
    ll ans = 1;
    if (B-A <= 2 || K <= A-1) {
        cout << K+1 << endl;
        return 0;
    }
    K -= A-1;
    ans += A-1;
    ll count = K/2;
    ans += count*(B-A) + K%2;
    cout << ans << endl;
    return 0;
}
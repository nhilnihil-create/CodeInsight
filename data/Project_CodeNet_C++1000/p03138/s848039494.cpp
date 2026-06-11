#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    ll K; cin >> K;
    vector<ll> A(N);
    ll maxA = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        maxA = max(maxA, A[i]);
    }

    auto digit = [](ll n) {
        int res = 0;
        while (n) {
            res++;
            n >>= 1;
        }
        return res;
    };

    int d = max(digit(maxA), digit(K));
    vector<int> count(d);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < d; j++) {
            count[j] += A[i] & 1;
            A[i] >>= 1;
        }
    }

    vector<ll> dp(2);
    bool flag = false;
    for (int i = d-1; i >= 0; i--) {
        ll bit = K & 1LL << i;
        ll x = 1LL << i;
        if (!flag) {
            dp[0] += x * count[i];
            if (bit) {
                dp[1] += x * (N-count[i]);
                flag = true;
            }
            else
                dp[1] += x * count[i];
        }
        else {
            int c = max(count[i], N-count[i]);
            dp[0] += x * c;
            if (bit) {
                dp[0] = max(dp[0], dp[1] + x * count[i]);
                dp[1] += x * (N-count[i]);
            }
            else
                dp[1] += x * count[i];
        }
    }
    cout << max(dp[0], dp[1]) << "\n";
}
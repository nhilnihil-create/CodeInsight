#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    int N, A, B, K;
    cin >> A >> B >> K;
    if (B - A + 1 < 2 * K) {
        for (int i = A; i <= B; i++) {
            cout << i << "\n";
        }
    } else {
        for (int i = A; i < A + K; i++) {
            cout << i << "\n";
        }
        for (int i = B - K + 1; i <= B; i++) {
            cout << i << "\n";
        }
    }
}
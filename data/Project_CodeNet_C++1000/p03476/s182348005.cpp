#include "bits/stdc++.h"

using namespace std;

void Main() {
    int Q;
    cin >> Q;

    int N = 100010;
    vector<bool> like2017(N + 1, false);
    for (int i = 2; i < N + 1; ++i) {
        if (i % 2 == 0) {
            continue;
        }
        bool isPrime1 = true;
        bool isPrime2 = true;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                isPrime1 = false;
            }
            if (((i + 1) / 2) % j == 0) {
                isPrime2 = false;
            }
            if (!isPrime1 && !isPrime2) {
                break;
            }
        }
        if (isPrime1 && isPrime2) {
            like2017[i] = true;
        }
    }

    vector<int> accumLike2017(N + 1, 0);
    for (int i = 1; i < N + 1; ++i) {
        accumLike2017[i] = accumLike2017[i - 1];
        if (like2017[i]) {
            accumLike2017[i] += 1;
        }
    }

    for (int i = 0; i < Q; ++i) {
        int l, r;
        cin >> l >> r;
        int ans = accumLike2017[r] - accumLike2017[l];
        if (like2017[l]) {
            ans += 1;
        }
        cout << ans << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}

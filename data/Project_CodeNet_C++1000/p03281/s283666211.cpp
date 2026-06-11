#include "bits/stdc++.h"

using namespace std;

int numDiv(int n) {
    int ret = 0;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            ++ret;
        }
    }
    return ret;
}

void Main() {
    int N;
    cin >> N;

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        if (i % 2 == 1 && 8 == numDiv(i)) {
            ++ans;
        }
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}

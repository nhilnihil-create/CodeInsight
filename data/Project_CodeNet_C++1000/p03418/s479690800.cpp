#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    if (k == 0) return !(cout << 1LL * n * n << endl);
    long long cnt = 0;
    for (int b = 1; b <= n; b++) {
        int q = n / b, r = n % b;
        cnt += 1LL * q * max(0, b - k) + max(0, r - k + 1);
    }
    cout << cnt << endl;
    return 0;
}

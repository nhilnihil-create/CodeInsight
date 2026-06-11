#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N, T, A, ans = 0; cin >> N >> T >> A;
    long double diff = 10e7 * 1.0;
    for (int i = 0; i < N; ++i) {
        int h; cin >> h;
        long double temp = T - (h * 0.006);
        if (diff >= abs(A - temp)) {
            diff = abs(A - temp);
            ans = i + 1;
        }
    }
    printf("%d\n", ans);
}

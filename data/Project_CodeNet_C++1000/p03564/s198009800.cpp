#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N, K, ans = 1; cin >> N >> K;
    for (int i = 0; i < N; i++) {
        if (ans + K >= 2 * ans) ans *= 2;
        else ans += K;
    }
    printf("%d\n", ans);
}

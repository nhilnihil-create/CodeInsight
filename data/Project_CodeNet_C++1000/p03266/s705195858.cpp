#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <utility>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    long n, k;
    cin >> n >> k;
    long ans = 0;
    if (k % 2 == 0) {
        long half = 0;
        for (int i = 1; i <= n; i++) {
            if (i % k == k / 2) {
                half++;
            }
        }
        ans += half * half * half;
    }
    long mult = 0;
    for (int i = 1; i <= n; i++) {
        if (i % k == 0) {
            mult++;
        }
    }
    ans += mult * mult * mult;
    cout << ans << endl;
}

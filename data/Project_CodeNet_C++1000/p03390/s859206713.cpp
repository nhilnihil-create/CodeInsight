#include <iostream>
using namespace std;

long long solve(long long a, long long b) {
    if (a == b) return (a-1)*2;
    long long lim = a*b - 1;
    long long low = 1, high = 1LL<<31;
    while (high - low > 1) {
        long long mid = (low + high) / 2;
        long long mul = (mid+1)/2 * (mid+1 - (mid+1)/2);
        if (mul > lim) high = mid;
        else low = mid;
    }
    return low - 1;
}

int main() {
    int Q; cin >> Q;
    for (int q = 0; q < Q; ++q) {
        long long a, b; cin >> a >> b;
        cout << solve(a, b) << endl;
    }
}
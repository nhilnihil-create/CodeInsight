#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

long long cube(long long x) { return x * x * x; }

int main() {
    int n, k; cin >> n >> k;
    vector<int> cnt(k);
    for (int i = 1; i <= n; i++) cnt[i % k]++;
    if (k % 2) {
        cout << cube(cnt[0]) << endl;
    } else {
        cout << cube(cnt[0]) + cube(cnt[k / 2]) << endl;
    }
    return 0;
}

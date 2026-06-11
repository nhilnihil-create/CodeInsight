#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    vector<bitset<64>> sums;
    for (int i = 0; cin >> a[i]; i++) {
        long long sum = 0;
        for (int j = i; j >= 0; j--) {
            sum += a[j];
            sums.emplace_back(sum);
        }
    }
    for (int i = 63; i >= 0; i--) {
        vector<bitset<64>> next;
        for (auto& j : sums) {
            if (j[i]) {
                next.emplace_back(j);
            }
        }
        if (next.size() >= k) {
            sums = move(next);
        }
    }
    bitset<64> result = sums.front();
    for (int i = 1; i < sums.size() && i < k; i++) {
        result = result & sums[i];
    }
    cout << result.to_ullong();
    return 0;
}

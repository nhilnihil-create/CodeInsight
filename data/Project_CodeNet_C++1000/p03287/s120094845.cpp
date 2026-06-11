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
    int n, m;
    cin >> n >> m;
    int sum = 0;
    unordered_map<int, long> counter;
    counter[0]++;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum = (sum + a % m) % m;
        counter[sum]++;
    }
    long ans = 0;
    for (auto&& e : counter) {
        ans += e.second * (e.second - 1) / 2;
    }
    cout << ans << endl;
}

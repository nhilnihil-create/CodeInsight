#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, result = 0;
    cin >> n;
    map<int, int> count;
    for (int i = 0, k; i < n; i++) {
        cin >> k;
        count[k]++;
    }
    while (!count.empty()) {
        if (count.rbegin()->second == 0) {
            count.erase(prev(count.rbegin().base()));
            continue;
        }
        int a = count.rbegin()->first, pow2 = 1;
        count.rbegin()->second--;
        while (pow2 <= a) {
            pow2 *= 2;
        }
        auto it = count.find(pow2 - a);
        if (it != end(count) && it->second > 0) {
            it->second--;
            result++;
        }
    }
    cout << result;
    return 0;
}
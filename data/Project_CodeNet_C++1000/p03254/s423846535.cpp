#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> weights(n);
    for (size_t i = 0; i < n; ++i) cin >> weights[i];
    sort(weights.begin(), weights.end());
    int num = 0;
    for (size_t i = 0; i < n; ++i) {
        ++num;
        x = x - weights[i];
        if (x < 0) break;
    }
    if (x != 0) --num;
    cout << num << endl;
    return EXIT_SUCCESS;
}
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> p(n);
    for (auto &pi: p) cin >> pi;
    int sum = accumulate(begin(p), end(p), 0);
    int ma = *max_element(begin(p), end(p));
    cout << sum - (ma + 1) / 2 << endl;
    return 0;
}

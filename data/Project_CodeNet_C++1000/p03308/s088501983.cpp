#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    uint N;
    cin >> N;
    vector<int> A(N, 0);
    for (auto &a: A) cin >> a;
    auto iter = minmax_element(A.begin(), A.end());
    int ans = *iter.second - *iter.first;
    cout << ans << endl;
}

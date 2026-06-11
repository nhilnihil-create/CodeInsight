#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    std::vector<int> a;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        a.push_back(k - i);
    }
    partial_sort(a.begin(), a.begin() + (n + 1) / 2, a.end());
    long sumu = 0;
    long sumd = 0;
    for (int i = 0; i < a.size(); i++) {
        sumu += abs(a[i] - a[n / 2]);
        sumd += abs(a[i] - a[(n - 1) / 2]);
    }
    cout << min(sumu, sumd) << endl;
}

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> x(n);
    vector<int> sorted(n);

    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        x[i] = a;
        sorted[i] = a;
    }
    sort(sorted.begin(), sorted.end());

    for (int i = 0; i < n; ++i) {
        int mid = n / 2 - 1;
        mid += x[i] <= sorted[mid];
        cout << sorted[mid] << endl;
    }
}


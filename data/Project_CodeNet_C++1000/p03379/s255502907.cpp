#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    vector<int> sorted = v;
    sort(sorted.begin(), sorted.end());

    for (int i = 0; i < n; i++) {
        if (v[i] <= sorted[n / 2 - 1])cout << sorted[n / 2] << endl;
        else cout << sorted[n / 2 - 1] << endl;
    }
    return 0;
}
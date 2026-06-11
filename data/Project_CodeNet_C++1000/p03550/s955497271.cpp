#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    int n, z, w;
    cin >> n >> z >> w;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if (n == 1) {
        cout << abs(w - v[0]) << endl;
        return 0;
    }
    cout << max(abs(w - v[n - 1]), abs(v[n - 1] - v[n - 2])) << endl;
}

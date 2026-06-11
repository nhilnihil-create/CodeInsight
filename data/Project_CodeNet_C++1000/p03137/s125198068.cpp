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
    int n, m;
    cin >> n >> m;
    vector<int> v(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int res = v.back() - v[0];
    vector<int> gap;
    for (int i = 0; i < m - 1; i++) {
        gap.push_back(v[i + 1] - v[i]);
    }
    sort(gap.begin(), gap.end(), greater<int>());
    for (int i = 0; i < min(n - 1, (int)gap.size()); i++) {
        res -= gap[i];
    }
    cout << res << endl;
}

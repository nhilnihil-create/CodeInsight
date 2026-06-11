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
    int n, x;
    cin >> n >> x;
    vector<int> v(n, 0);
    int res = n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        x -= v[i];
    }
    sort(v.begin(), v.end());
    cout << res + x / v[0] << endl;
}

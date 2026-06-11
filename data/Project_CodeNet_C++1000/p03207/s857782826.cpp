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
    int n;
    cin >> n;
    vector<int> v(n , 0);
    for (int i = 0; i < n; i++) {
    	cin >> v[i];
    }
    sort(v.begin(), v.end());
    int res = accumulate(v.begin(), v.end(), 0);
    res -= v.back() / 2;
    cout << res << endl;
}

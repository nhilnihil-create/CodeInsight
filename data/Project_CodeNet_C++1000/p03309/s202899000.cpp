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
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
    	cin >> v[i];
    	v[i] -= i + 1;
    }
    sort(v.begin(), v.end());
    long long int res = 0;
    for (int i = 0; i < n - 1 - i; i++) {
    	res += v[n - 1 - i] - v[i];
    }
    cout << res << endl;
}

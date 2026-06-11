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
    vector<long long int> v(n, 0);
    unordered_map<int, int> um;
    um[0] = 1;
    long long int res = 0;
    long long int c = 0;
    for (int i = 0; i < n; i++) {
    	cin >> v[i];
    	c += v[i];
    	res += um[c % m];
    	um[c % m]++;
    }
    cout << res << endl;
}

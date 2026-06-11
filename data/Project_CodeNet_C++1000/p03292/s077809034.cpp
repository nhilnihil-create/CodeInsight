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
    vector<int> v(3, 0);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    cout << v[1] - v[0] + v[2] - v[1] << endl;
}

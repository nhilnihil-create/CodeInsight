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
    if (v[0] != v[1]) cout << v[0] << endl;
    if (v[1] != v[2]) cout << v[2] << endl;
}



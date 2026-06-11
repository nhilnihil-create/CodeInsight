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
    vector<long long int> v{2, 1};
    for (int i = 2; i <= n; i++) {
        v.push_back(v[i - 1] + v[i - 2]);
    }
    cout << v[n] << endl;
}

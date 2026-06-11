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
    long long int a, b;
    long long int res = 0;
    vector<long long int> v;
    int c = 0;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        res += a + b;
        if (a < b) {
        } else {
            c++;
            if (a > b) v.push_back(b);
        }
    }
    sort(v.begin(), v.end());
    if (c == n) {
        cout << 0 << endl;
    } else {
        cout << res / 2 - v[0] << endl;
    }
}








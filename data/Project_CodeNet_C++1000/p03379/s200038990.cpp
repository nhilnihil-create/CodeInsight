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
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector<int> v_temp = v;
    sort(v.begin() + 1, v.end());
    for (int i = 1; i <= n; i++) {
        if (v_temp[i] >= v[n / 2 + 1]) {
            cout << v[n / 2] << endl;
        } else {
            cout << v[n / 2 + 1] << endl;
        }
    }
}

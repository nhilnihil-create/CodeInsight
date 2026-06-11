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
    vector<vector<int>> v;
    for (int i = 0; i < n - 1; i++) {
        vector<int> vv(3, 0);
        cin >> vv[0] >> vv[1] >> vv[2];
        v.push_back(vv);
    }
    for (int i = 0; i < n - 1; i++) {
        int t = v[i][1];
        for (int j = i; j < n - 1; j++) {
            t = max(t, v[j][1]);
            if ((t - v[j][1]) % v[j][2] > 0) {
                t = v[j][1] + ((t - v[j][1]) / v[j][2] + 1) * v[j][2];
            }
            t += v[j][0];
        }
        cout << t << endl;
    }
    cout << 0 << endl;
}



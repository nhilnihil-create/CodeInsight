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
    vector<vector<long long int>> v(8, vector<long long int>(0));
    for (int i = 0; i < n; i++) {
        long long int a, b, c;
        cin >> a >> b >> c;
        for (int ia = -1; ia <= 1; ia += 2) {
            for (int ib = -1; ib <= 1; ib += 2) {
                for (int ic = -1; ic <= 1; ic += 2) {
                    int index = 0;
                    if (ia == 1) index += 4;
                    if (ib == 1) index += 2;
                    if (ic == 1) index += 1;
                    v[index].push_back(ia * a + ib * b + ic * c);
                }
            }
        }
    }
    long long int res = 0;
    for (int i = 0; i < 8; i++) {
        sort(v[i].begin(), v[i].end(), greater<long long int>());
        res = max(res, accumulate(v[i].begin(), v[i].begin() + m, (long long int)0));
    }
    cout << res << endl;
}

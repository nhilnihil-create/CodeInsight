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
    int n, g;
    cin >> n >> g;
    vector<int> vp(n, 0), vc(n, 0), vt(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> vp[i] >> vc[i];
        vt[i] = vp[i] * (i + 1) * 100 + vc[i];
    }
    int t = (1 << n);
    vector<int> v(t, 0);
    int res = 0x3f3f3f3f;
    for (int i = 0; i < t; i++) {
        int index = i;
        for (int j = 0; j < n; j++) {
            if (index % 2 == 1) {
                v[i] = v[i - (1 << j)] + vt[j];
                break;
            }
            index /= 2;
        }
        int c = 0;
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) > 0) {
                c += vp[j];
            }
        }
        for (int j = 0; j < n; j++) {
            if (v[i] >= g) {
                res = min(res, c);
                break;
            }
            if ((i & (1 << j)) == 0 && v[i] + vp[j] * (j + 1) * 100 >= g) {
                int diff = g - v[i];

                res = min(res, c + diff / (j * 100 + 100) + (diff % (j * 100 + 100) > 0 ? 1 : 0));
            }
        }
    }
    cout << res << endl;

}

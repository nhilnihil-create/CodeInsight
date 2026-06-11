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
    vector<int> vt(n, 0), vv(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> vt[i];
    }
    for (int i = 0; i < n; i++ ) {
        cin >> vv[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            vv[i] = min(vv[i], vt[i]);
        } else {
            vv[i] = min(vv[i], vv[i + 1] + vt[i]);
        }
    }

    int v = 0;
    int res = 0;
    int r = 0;
    for (int i = 0; i < n; i++) {
        int next = 0;
        int now = vv[i];
        if (i + 1 < n) next = vv[i + 1];
        for (int j = 1; j <= vt[i]; j++) {
            if (v - (vt[i] - j + 1) == next) {
                v--;
            } else if (v - (vt[i] - j + 1) == next - 1) {
                if (v != now) r++;
            } else {
                if (v < now) v++;
            }
            res += v;
        }
    }
    cout << res + r / 4;
    if (r % 4 > 0) {
        cout << "." << (r % 4) * 25;
    }
    cout << endl;
}



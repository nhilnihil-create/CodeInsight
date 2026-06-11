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
    string s;
    cin >> s;

    vector<int> v1(n, 0), v2(n, 0);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            v1[i] = (s[i] == 'E' ? 1 : 0);
        } else {
            v1[i] += v1[i - 1] + (s[i] == 'E' ? 1 : 0);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            v2[i] = (s[i] == 'W' ? 1 : 0);
        } else {
            v2[i] += v2[i + 1] + (s[i] == 'W' ? 1 : 0);
        }
    }

    int res = n;
    for (int i = 0; i < n; i++) {
        res = min(res, (i > 0 ? i - v1[i - 1] : 0) + (i < n - 1 ? n - 1 - i - v2[i + 1] : 0));
    }
    cout << res << endl;
}

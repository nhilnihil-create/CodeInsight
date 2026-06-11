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
    vector<int> v1(26, 0), v2(26, 0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        v1[s[i] - 'a']++;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        v2[s[i] - 'a']++;
        int r = 0;
        for (int j = 0; j < 26; j++) {
            if (v2[j] > 0 && v1[j] - v2[j] > 0) {
                r++;
            }
        }
        res = max(res, r);
    }
    cout << res << endl;
}

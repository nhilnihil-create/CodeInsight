#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <utility>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> tmp;
    vector<int> sumn(1, 0);
    vector<int> sump(1, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < 0) {
            tmp.push_back(x);
        } else {
            sump.push_back(x);
        }
    }
    for (int i = tmp.size()-1; i >= 0; i--) {
        sumn.push_back(-tmp[i]);
    }

    int ans = 1e9;
    if (sumn.size() > k && ans > sumn[k]) {
        ans = sumn[k];
    }
    if (sump.size() > k && ans > sump[k]) {
        ans = sump[k];
    }
    for (int i = 1; i < sumn.size(); i++) {
        if (sump.size() > k - i) {
            ans = min(ans, 2 * sumn[i] + sump[k - i]);
        }
    }
    for (int i = 1; i < sump.size(); i++) {
        if (sumn.size() > k - i) {
            ans = min(ans, 2 * sump[i] + sumn[k - i]);
        }
    }
    cout << ans << endl;
}

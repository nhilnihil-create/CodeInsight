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
    int n, k;
    cin >> n >> k;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int num = *min_element(v.begin(), v.end());
    int index = 0;
    int res = 0;
    while (index < n) {
        if (v[index] == num) {
            index++;
            continue;
        }
        int begin = index;
        while (index < n && v[index] != num) {
            index++;
        }
        if (index == n) {
            cout << res + (n - begin) / (k - 1) + ((n - begin) % (k - 1) > 0 ? 1 : 0) << endl;
            return 0;
        } else {
            res = res + (index - begin) / (k - 1) + ((index - begin) % (k - 1) > 0 ? 1 : 0);
            if ((index - begin) % (k - 1) == 0) {
                index++;
            } else {
                index = (index - begin) / (k - 1) * (k - 1) + k;
            }
        }
    }
    cout << res << endl;
}

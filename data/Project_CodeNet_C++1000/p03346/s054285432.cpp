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
    vector<int> index(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        index[v[i]] = i;
    }
    vector<int> res(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        if (index[i] > index[i - 1]) {
            res[i] = res[i - 1] + 1;
        } else {
            res[i] = 1;
        }
    }
    cout << n - *max_element(res.begin() + 1, res.end()) << endl;
}

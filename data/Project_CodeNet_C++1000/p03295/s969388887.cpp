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
    vector<pair<int, int>> vp;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        vp.push_back(make_pair(b, a));
    }
    sort(vp.begin(), vp.end());
    int res = 0;
    int index = -1;
    for (int i = 0; i < m; i++) {
        if (index <= vp[i].second) {
            res++;
            index = vp[i].first;
        }
    }
    cout << res << endl;
}

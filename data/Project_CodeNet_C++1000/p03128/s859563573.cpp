#include <algorithm>
#include <climits>
#include <cmath>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>

using Graph = std::vector<std::vector<int>>;
using WGraph = std::vector<std::vector<std::pair<int, long long>>>;
using ll = long long;
using namespace std;

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> a(m);
    for (int i=0; i<m; i++) {
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    vector<int> match = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    vector<int> dp(n+1, -1e8);
    dp.at(0) = 0;
    for (int i=1; i<n+1; i++) {
        for (int j=0; j<m; j++) {
            int use = match.at(a.at(j));
            if (i - use < 0) {
                continue;
            }
            else {
                dp.at(i) = max(dp.at(i), dp.at(i-use)+1);
            }
        }
    }
    vector<int> ret;
    while (n > 0) {
        for (int i=0; i<m; i++) {
            int use = match.at(a.at(i));
            if (n - use < 0) continue;
            if (dp.at(n) == dp.at(n-use)+1) {
                ret.push_back(a.at(i));
                n -= use;
                break;
            }
        }
    }
    for (int x : ret) {
        cout << x;
    }
    cout << endl;
    return 0;
}
 
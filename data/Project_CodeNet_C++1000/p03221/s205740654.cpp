#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;



int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<pair<int,int>>> C(n + 1);

    for (int i = 0; i < m; ++i) {
        int p, y;
        cin >> p >> y;
        C[p].emplace_back(y, i);
    }
    
    for (auto& V : C) {
        sort(V.begin(), V.end());
    }

    vector<string> res(m);

    for (int i = 0; i <= n; ++i) {
        string pre = to_string(i);
        if (pre.length() < 6) {
            pre = string(6 - pre.length(), '0') + pre;
        }

        for (int j = 0; j < C[i].size(); ++j) {
            int x = j + 1;
            string sfx = to_string(x);
            if (sfx.length() < 6) {
                sfx = string(6 - sfx.length(), '0') + sfx;
            }
            res[C[i][j].second] = pre + sfx;
        }
    }

    for (int i = 0; i < m; ++i) {
        cout << res[i] << '\n';
    }

    return 0;
}
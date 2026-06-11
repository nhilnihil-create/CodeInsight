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

    int _;
    cin >> _;
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> cnts(n + 1, vector<int>(26, 0));

    for (int i = 0; i < n; ++i) {
        cnts[i + 1] = cnts[i];
        cnts[i + 1][s[i] - 'a'] += 1;
    }

    int res = 0;
    for (int i = 1; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < 26; ++j) {
            if (cnts[i][j] > 0 && cnts[n][j] > cnts[i][j]) {
                ++cnt;
            }
        }
        res = max(res, cnt);
    }

    cout << res << '\n';

    return 0;
}
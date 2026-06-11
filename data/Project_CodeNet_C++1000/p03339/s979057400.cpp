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
    string s;
    cin >> s;

    vector<vector<int>> cnts(n + 1, vector<int>(2, 0));

    for (int i = 0; i < n; ++i) {
        cnts[i + 1] = cnts[i];
        cnts[i + 1][s[i] == 'E'] += 1;
    }

    int res = n;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        cnt += cnts[i][0];
        cnt += cnts[n][1] - cnts[i + 1][1];
        res = min(res, cnt);
    }

    cout << res << '\n';
    
    return 0;
}
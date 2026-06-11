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

    vector<int> cnts(128, 0);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        cnts[s[0]] += 1;
    }

    string S = "MARCH";
    int m = S.length();
    long long res = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            for (int k = j + 1; k < m; ++k) {
                long long cnt = cnts[S[i]] * 1LL * cnts[S[j]] * 1LL * cnts[S[k]];
                res += cnt;
            }
        }
    }

    cout << res << '\n';

    return 0;
}
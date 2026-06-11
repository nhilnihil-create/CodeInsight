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

    string s;
    cin >> s;
    int n = s.length();
    if (s[0] == '0' || s[n - 1] == '1') {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 0, j = n - 2; i < j; ++i, --j) {
        if (s[i] != s[j]) {
            cout << -1 << '\n';
            return 0;
        }
    }

    vector<pair<int,int>> res;
    vector<int> pars(n, -1);
    {
        int u = n;
        int p = n - 1;
        res.emplace_back(u, p);
        u = p;
        for (int i = 2; i < n; ++i) {
            if (s[i - 1] == '1') {
                --p;
                res.emplace_back(u, p);
                u = p;
            } else {
                --p;
                res.emplace_back(u, p);
            }
        }
    }
    for (auto& e : res) {
        cout << e.first << ' ' << e.second << '\n';
    }


    return 0;
}
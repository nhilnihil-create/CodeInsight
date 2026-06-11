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
    cout << fixed << setprecision(12);

    string S, T;

    cin >> S >> T;

    auto check = [&](const string& s, const string& t) {
        int n = s.length();
        if (n == t.length()) {
            for (int i = 0; i < n; ++i) {
                if (s[i] == t[i] || s[i] == '?') {

                } else {
                    return false;
                }
            }
            return true;
        }
        return false;
    };


    string res;
    int n = S.length(), m = T.length();
    for (int i = 0; i + m <= n; ++i) {
        if (check(S.substr(i, m), T)) {
            string s = S.substr(0, i);
            s += T;
            s += S.substr(i + m);
            for (auto& c : s) {
                if (c == '?') {
                    c = 'a';
                }
            }
            if (res.empty()) {
                res = s;
            } else {
                res = min(res, s);
            }
        }
    }

    if (res.empty()) {
        cout << "UNRESTORABLE" << '\n';
    } else {
        cout << res << '\n';
    }


    return 0;
}
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

    string S;
    cin >> S;
    int n = S.length();
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        A[i] = S[i] - '0';
    }
    int m = n - 1;
    int M = 1 << m;

    auto check = [&](int mask) -> string {
        string res;
        res += (char) ('0' + A[0]);
        int ans = A[0];
        for (int i = 0; i < n - 1; ++i) {
            if ((mask >> i) & 1) {
                res += '+';
                ans += A[i + 1];
            } else {
                res += '-';
                ans -= A[i + 1];
            }
            res += (char)('0' + A[i + 1]);
        }

        if (ans == 7) {
            res += "=7";
            return res;
        } else {
            return "";
        }
    };

    for (int i = 0; i < M; ++i) {
        auto res = check(i);
        if (!res.empty()) {
            cout << res << '\n';
            break;
        }
    }

    return 0;
}
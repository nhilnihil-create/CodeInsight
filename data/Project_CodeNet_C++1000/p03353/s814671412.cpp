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

    string S;
    int K;
    cin >> S >> K;

    int n = S.length();


    vector<int> cnts(27, 0);
    vector<int> A(n, 0);
    iota(A.begin(), A.end(), 0);
    vector<int> tmp(n, 0);

    auto index = [&](int beg, int pos) {
        if (beg + pos >= n) {
            return 0;
        } else {
            return S[beg + pos] - 'a' + 1;
        }
    };

    string res;
    function<bool(int,int,int,int&,int)> dfs = [&](int len, int l, int r, int& idx, int K) -> bool {
        if (l >= r) {
            return false;
        }
        if (++idx == K) {
            res = S.substr(A[l], len);
            return true;
        }
        // cout << idx << ": " << S.substr(A[l], len) << endl;
        fill(cnts.begin(), cnts.end(), 0);
        for (int i = l; i < r; ++i) {
            int x = A[i];
            ++cnts[index(x, len)];
        }
        for (int i = 1; i < cnts.size(); ++i) {
            cnts[i] += cnts[i - 1];
        }

        for (int i = l; i < r; ++i) {
            int x = A[i];
            tmp[l + (--cnts[index(x, len)])] = x;
        }
        for (int i = l; i < r; ++i) {
            A[i] = tmp[i];
        }

        for (int i = l; i < r; ++i) {
            int x = A[i];
            int ch = index(x, len);
            int ll = i;
            while (i + 1 < r && index(A[i + 1], len) == ch) {
                ++i;
            }
            int rr = i + 1;

            if (ch == 0) {
                continue;
            }

            if (dfs(len + 1, ll, rr, idx, K)) {
                return true;
            }
        }

        return false;
    };

    int idx = -1;
    dfs(0, 0, n, idx, K);

    cout << res << '\n';
    return 0;
}
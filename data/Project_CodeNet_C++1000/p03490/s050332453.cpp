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
    cin >> S;

    int x, y;
    cin >> x >> y;


    vector<int> X;
    vector<int> Y;
    
    int n = S.length();
    int len = 0;
    int d = 0;
    for (int i = 0; i < n; ++i) {
        if (S[i] == 'T') {
            if (d == 0) {
                X.push_back(len);
            } else {
                Y.push_back(len);
            }
            d ^= 1;
            len = 0;
            continue;
        }
        ++len;
    }
    if (d == 0) {
        X.push_back(len);
    } else {
        Y.push_back(len);
    }

    auto check = [&](vector<int>& A, int beg, long long target) {
        int n = A.size();
        const int M = 8000 * 3 + 10;
        int offset = 8000 + 1;

        bitset<M> bits;
        bits.set(offset);
        auto nbits = bits;
        for (int i = beg; i < n; ++i) {
            nbits.reset();

            nbits |= bits << A[i];
            nbits |= bits >> A[i];
            bits = nbits;
        }

        if (target + offset >= 0 && target + offset < M) {
            return bits.test(target + offset);
        } else {
            return false;
        }
    };

    bool res = false;
    if (check(X, 1, x - X[0]) && check(Y, 0, y)) {
        res = true;
    }
    if (res) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
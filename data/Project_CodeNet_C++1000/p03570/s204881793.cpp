#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;


int bc(int v) {
    int ans = 0;
    for (; v > 0; v >>= 1) {
        ans += v & 1;
    }
    return ans;
}

string S;

map<int, int> w;

int main() {
    cin >> S;
    const int N = S.size();

    int p[202020];
    fill(p, p+N, 0);

    for (int j = 0; j < N; ++j) {
        p[j] |= (1 << (S[j] - 'a'));
        if (j > 0) p[j] ^= p[j-1];
    }

    int m[202020];
    for (int j = 0; j < N; ++j) m[j] = j+1;
    m[0] = 1;
    w[p[0]] = 0;
    for (int j = 1; j < N; ++j) {
        if (bc(p[j]) <= 1) {
            m[j] = 1;
        }

        int v = p[j];
        for (int k = 0; k < 26; ++k) {
            int x = v ^ (1 << k);
            if (w.find(x) != end(w)) {
                m[j] = min(m[j], m[w[x]] + 1);
            }
        }
        if (w.find(v) != end(w)) {
            m[j] = min(m[j], m[w[v]] + 1);
        }
        w[p[j]] = j;
    }
    cout << m[N-1] << endl;

    return 0;
}

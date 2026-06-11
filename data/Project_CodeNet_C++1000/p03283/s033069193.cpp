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

class FenwickTree {
    public:
        FenwickTree(int n ) : N(n), data(n, 0) {

        }

        void put(int x, int v) {
            for (; x < N; x |= x + 1) {
                data[x] += v;
            }
        }
        int get(int x) {
            int res = 0;
            for (; x >= 0; x = (x & (x + 1)) - 1) {
                res += data[x];
            }
            return res;
        }

    private:
        int N;
        vector<int> data;
};


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    int q;
    cin >> n >> m;
    cin >> q;

    vector<pair<int,int>> P;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        P.emplace_back(l, r);
    }

    vector<pair<int,int>> Q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        Q.emplace_back(l, r);
    }

    vector<int> res(q, 0);

    vector<int> A(m, 0);
    iota(A.begin(), A.end(), 0);
    sort(A.begin(), A.end(), [&](int l, int r) { return P[l] < P[r];});
    vector<int> B(q, 0);
    iota(B.begin(), B.end(), 0);
    sort(B.begin(), B.end(), [&](int l, int r) { return Q[l] < Q[r];});

    FenwickTree ft(n + 123);
    for (int i = m - 1, j = q - 1; j >= 0; --j) {
        int L = Q[B[j]].first;
        int R = Q[B[j]].second;
        while (i >= 0) {
            int l = P[A[i]].first;
            int r = P[A[i]].second;
            if (l >= L) {
                ft.put(r, 1);
                --i;
            } else {
                break;
            }
        }

        res[B[j]] = ft.get(R);
    }
  
    for (int i = 0; i < q; ++i) {
        cout << res[i] << '\n';
    }


    return 0;
}
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

    int n, K;
    cin >> n >> K;
    vector<int> T(n);
    vector<int> D(n);
    for (int i = 0; i < n; ++i) {
        cin >> T[i] >> D[i];
        --T[i];
    }

    vector<int> maxs(n, 0);
    vector<int> cnts(n, 0);

    for (int i = 0; i < n; ++i) {
        maxs[T[i]] = max(maxs[T[i]], D[i]);
    }

    vector<int> ord(n, 0);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int l, int r) { return D[l] > D[r]; });

    long long res = 0;

    long long ans = 0;
    int cnt = 0;
    for (int i = 0; i < K; ++i) {
        ans += D[ord[i]];
        if (cnts[T[ord[i]]]++ == 0) {
            ++cnt;
        }
    }
    res = max(res, ans + cnt * 1LL * cnt);

    vector<int> M;
    for (int i = 0; i < n; ++i) {
        if (cnts[i] == 0 && maxs[i] > 0) {
            M.push_back(maxs[i]);
        }
    }
    sort(M.begin(), M.end(), greater<int>());

    for (int i = K - 1, j = 0; i >= 0 && j < M.size(); --i) {
        if (--cnts[T[ord[i]]] > 0) {
            cnt += 1;
            ans -= D[ord[i]];
            ans += M[j++];
            res = max(res, ans + cnt * 1LL * cnt);
        }
    }

    cout << res << '\n';

    return 0;
}
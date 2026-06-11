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


    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    int mn = 1 << 29;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        mn = min(mn, x);
        A[i] = x;
    }

    int p = 0;
    for (int i = 0; i < n; ++i) {
        if (A[i] == mn) {
            p = i;
            break;
        }
    }

    int res = n + 1234;
    for (int i = max(0, p - k + 1); i <= min(n - k, p); ++i) {
        int ans = 1 + (i + k - 2) / (k - 1) + (max(0, n - 1 - (i + k - 1)) + k - 2) / (k - 1);
        res = min(res, ans);
        // cout << i << " " << ans << endl;
    }

    cout << res << '\n';

    return 0;
}
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
    vector<int> X(n);
    for (int i = 0; i < n; ++i) {
        cin >> X[i];
    }

    long long res = 1LL << 60;
    for (int i = 0; i + k <= n; ++i) {
        int l = X[i];
        int r = X[i + k - 1];

        long long ans = r - l + min(abs(r), abs(l));
        res = min(res, ans);
    }

    cout << res << '\n';

    return 0;
}
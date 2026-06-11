#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <limits>
#include <climits>
#include <utility>
#include <algorithm>
#include <numeric>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int main()
{
    ll A, B, K;
    cin >> A >> B >> K;

    // 多分使わなくても行けるはずだけど...場合分けがなぁ...わからん
    unordered_map<ll, ll> used;

    for (int i = 0; i < K; ++i) {
        ll n = A + i;
        if (A <= n && n <= B) {
            cout << n << endl;
            used[n] = 1;
        }
    }

    for (int i = 0; i < K; ++i) {
        ll n = B - K + i + 1;
        if (used[n]) {
            continue;
        }

        if (A <= n && n <= B) {
            cout << n << endl;
        }
    }

    return 0;
}

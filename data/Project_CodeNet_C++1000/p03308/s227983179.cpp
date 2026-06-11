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
    int N;
    cin >> N;

    ll min_a = 1e+10;
    ll max_a = 0;

    for (int i = 0; i < N; ++i) {
        ll a;
        cin >> a;

        min_a = min(min_a, a);
        max_a = max(max_a, a);
    }

    cout << max_a - min_a << endl;

    return 0;
}

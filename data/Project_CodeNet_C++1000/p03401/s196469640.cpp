#include <iostream> // cout, endl, cin
#include <iomanip>
#include <string>        // string, to_string, stoi
#include <vector>        // vector
#include <algorithm>     // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility>       // pair, make_pair
#include <tuple>         // tuple, make_tuple
#include <cstdint>       // int64_t, int*_t
#include <cstdio>        // printf
#include <map>           // map
#include <queue>         // queue, priority_queue
#include <set>           // set
#include <stack>         // stack
#include <deque>         // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset>        // bitset
#include <cctype>        // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <numeric>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
const int INF = 1001001001;

int main()
{
    int N;
    cin >> N;
    vector<int> v(N + 2);
    int sum = 0;
    rep2(i, 1, N + 1) cin >> v[i];

    rep2(i, 1, N + 2)
    {
        sum += abs(v[i] - v[i - 1]);
    }
    rep2(i, 1, N + 1)
    {
        int before = abs(v[i] - v[i - 1]);
        int after = abs(v[i + 1] - v[i]);
        int skip = abs(v[i + 1] - v[i - 1]);
        int ans = sum - before - after + skip;
        cout << ans << endl;
    }
}

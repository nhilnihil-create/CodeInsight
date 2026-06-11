#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <bitset>    // bitset
#include <cctype>    // isupper, islower, isdigit, toupper, tolower
#include <cstdint>   // int64_t, int*_t
#include <cstdio>    // printf
#include <deque>     // deque
#include <iomanip>
#include <iostream> // cout, endl, cin
#include <map>      // map
#include <math.h>
#include <numeric>
#include <queue>         // queue, priority_queue
#include <set>           // set
#include <stack>         // stack
#include <string>        // string, to_string, stoi
#include <tuple>         // tuple, make_tuple
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <utility>       // pair, make_pair
#include <vector>        // vector
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
const int INF = 1001001001;
const int BG = 1000000007;

int64_t f(int left, int right)
{
    int64_t res = 0;
    int tmp = right - left;
    for (int i = 0; i <= tmp; i++)
    {
        res += i;
    }
    return res;
}

int main()
{
    int N;
    cin >> N;
    vector<int64_t> A(N);
    rep(i, N) cin >> A[i];

    int left = 0, right = 0;
    int64_t sum = 0;
    int64_t cnt = 0;
    bitset<21> bt(0);

    for (; right < N; right++)
    {
        bitset<21> bt_now(A[right]);
        bt ^= bt_now;
        // cout << bt << endl;
        sum += A[right];
        while (bt.to_ullong() != sum)
        {
            // cout << "left:" << left << "/right:" << right << endl;
            cnt += right - left;
            bitset<21> tp(A[left]);
            bt ^= tp;
            sum -= A[left];
            left++;
        }
    }
    // cout << "left:" << left << "/right:" << right << endl;
    cnt += f(left, right);
    cout << cnt << endl;
}

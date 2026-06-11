#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <numeric>

using namespace std;

typedef uint64_t u64;
typedef int64_t s64;
typedef uint32_t u32;
typedef int32_t s32;
typedef vector<s32> vs32;
typedef vector<u32> vu32;
typedef vector<s64> vs64;
typedef vector<u64> vu64;

const double PI=3.14159265358979323846;

#define MAX(x, y) ((x) < (y) ? (y) : (x))
#define MIN(x, y) ((x) > (y) ? (y) : (x))

#define rep(i, N) for(int i = 0; i < N; ++i)

#define CEIL(x, y) (((x) + (y) - 1) / (y))
#define MOD 1000000007ULL

#define IN(l, r, x) ((l) <= (x) && (x) < (r))

const int max_n = 100001;
vector< bool > is_prime(max_n, true);
void init()
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= max_n; ++i)
    {
        if (is_prime[i])
        {
            for (int j = i + i; j <= max_n; j += i) is_prime[j] = false;
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    init();

    int sum[max_n + 1];
    sum[0] = 0;
    for (int i = 0; 2 * i + 1 <= max_n; ++i)
    {
        int num = 2 * i + 1;
        sum[num] = sum[num - 1] + (is_prime[num] && is_prime[i + 1]);
        if (num + 1 <= max_n) sum[num + 1] = sum[num];
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << "\n";
    }

    return 0;
}


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


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    s64 N;
    cin >> N;

    s64 x = 0, y = 0, z = 0;
    bool found = false;
    for (y = CEIL(N, 4); y <= 3500; ++y)
    {
        for (x = y; x <= 3500; ++x)
        {
            if ((N - 4 * y) * x + N * y == 0) continue;
            z = - N * x * y / ((N - 4 * y) * x + N * y);
            if (z > 3500) continue;
            if (z > 0 && 4 * x * y * z == (x * y + y * z + z * x) * N)
            {
                found = true;
            }
            if (found) break;
        }
        if (found) break;
    }

    cout << x << " " << y << " " << z << "\n";
    return 0;
}


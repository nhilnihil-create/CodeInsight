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

const double PI=3.14159265358979323846;

#define MAX(x, y) ((x) < (y) ? (y) : (x))
#define MIN(x, y) ((x) > (y) ? (y) : (x))

#define rep(i, N) for(int i = 0; i < N; ++i)

#define CEIL(x, y) (((x) + (y) - 1) / (y))
#define MOD 1000000007ULL

int p[2 * 100000];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int P;
    rep (i, N)
    {
        cin >> P;
        p[P - 1] = i;
    }

    int ans = 1;
    int previ = 0;
    for (int i = 0; i < N - 1; ++i)
    {
        while (i < N - 1 && p[i] < p[i + 1]) ++i;
        ans = MAX(i - previ + 1, ans);
        previ = i + 1;
    }

    cout << N - ans << "\n";

    return 0;
}


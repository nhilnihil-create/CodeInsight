#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef uint64_t u64;
typedef int64_t s64;
typedef uint32_t u32;
typedef int32_t s32;

#define MAX(x, y) ((x) < (y) ? (y) : (x))
#define MIN(x, y) ((x) > (y) ? (y) : (x))

#define rep(i, N) for(int i = 0; i < N; ++i)

u32 N;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    scanf("%u", &N);

    printf("%d\n", 180 * (N - 2));

    return 0;
}


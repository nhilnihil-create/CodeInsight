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

vector< vector<bool> > connect = vector< vector<bool> >(101, vector<bool>(101, true));

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int M;
    if (N & 1)
    {
        for (int i = 1; i <= N; ++i)
        {
            connect[i][N - i] = false;
        }
        M = (N - 1) * (N - 1) / 2;
    }
    else
    {
        for (int i = 1; i <= N; ++i)
        {
            connect[i][N - i + 1] = false;
        }
        M = N * (N - 2) / 2;
    }

    cout << M << "\n";
    for (int i = 1; i <= N; ++i)
    {
        for (int j = i + 1; j <= N; ++j)
        {
            if (connect[i][j])
            {
                cout << i << " " << j << "\n";
            }
        }
    }

    return 0;
}


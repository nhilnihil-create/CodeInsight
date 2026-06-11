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

enum
{
    MALE = 'M',
    FEMALE = 'F',
    VACANT = 'V'
};


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    string input;
    cin >> N;

    int cmd = 0;
    char zero = VACANT;
    cout << cmd << "\n";
    cout.flush();
    cin >> input;
    zero = input[0];
    int left = 0, right = N;
    cmd = (left + right) / 2;
    while (input[0] != 'V')
    {
        cout << cmd << "\n";
        cout.flush();
        cin >> input;
        /* generate next query */
        if (input[0] == zero)
        {
            if (cmd & 1) // odd
            {
                right = cmd;
            }
            else // even
            {
                left = cmd + 1;
            }
        }
        else
        {
            if (cmd & 1) // odd
            {
                left = cmd + 1;
            }
            else // even
            {
                right = cmd;
            }
        }
        cmd = (left + right) / 2;
    }

    return 0;
}


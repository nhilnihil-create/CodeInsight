#include <cstdio>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stack>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <functional>
#include <numeric>
#include <chrono>
#include <cstdlib>
using ll = long long;
using namespace std;

const ll MOD = 1e9 + 7;
#define REP(i, n) for (int(i) = 0; (i) < (n); ++(i))
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
// bool operator<(const pair<int, int> &a, const pair<int, int> &b)
// {
//     if (a.first == b.first)
//         return a.second < b.second;
//     return a.first < b.first;
// };

/*unsigned int xor128(void)
{
    static unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned int t = (x ^ (x << 11));
    x = y;
    y = z;
    z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
unsigned int xor128rnd(unsigned int m)
{
    return xor128() % m;
}*/

/*bool operator<(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}*/

int N, H, W;
double arr[3000];
double dp[3000][3000];
vector<int> v1, v2;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(12);
    cin >> N >> H >> W;

    cout << (N - H + 1) * (N - W + 1) << endl;
    return 0;
}
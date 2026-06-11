#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

const int Mod(const int n, const int mod)
{
    if (n > 0) return n % mod;
    else return Mod(n + mod, mod);
}

const bool IsOK(
    const int N, const vector<vector<char>> &grids,
    const int A, const int B)
{
    for (int x1 = 0; x1 < N; ++x1)
    {
        for (int y1 = 0; y1 < N; ++y1)
        {
            int x2 = Mod(y1 + B - A, N);
            int y2 = Mod(x1 + A - B, N);
            if (grids[x1][y1] != grids[x2][y2]) return false;
        }
    }
    return true;
}

int main()
{
    int N; cin >> N;
    vector<vector<char>> grids(N, vector<char>(N));
    for (int i = 0; i < N; ++i)
    {
        string S; cin >> S;
        for (int j = 0; j < N; ++j)
        {
            grids[i][j] = S[j];
        }
    }
    int ans = 0;
    int A = 0;
    for (int B = 0; B < N; ++B)
    {
        if (IsOK(N, grids, A, B)) ++ans;
    }
    cout << ans * N << endl;
}
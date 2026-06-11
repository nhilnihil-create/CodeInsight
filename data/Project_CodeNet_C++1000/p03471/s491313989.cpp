// https://atcoder.jp/contests/abc085/tasks/abc085_c
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <set>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int N, Y;
    cin >> N >> Y;
    for (int x = 0; x <= N; ++x)
    {
        int rhs = Y - 1000 * N - 9000 * x;
        if (rhs < 0 || rhs % 4000 != 0) continue;
        int y = rhs / 4000;
        int z = N - y - x;
        if (z >= 0)
        {
            cout << x << " " << y << " " << z << endl;
            return 0;
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
    return 0;
}

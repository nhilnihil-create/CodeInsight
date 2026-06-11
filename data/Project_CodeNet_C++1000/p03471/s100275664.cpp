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
    int yen[3] = {10000, 5000, 1000};
    int ans[3];
    int cnt = 0;
    bool ok = false;
    for (int i = 0; i <= N; ++i)
    {
        for (int j = 0; j <= N; ++j)
        {
            int k = N - i - j;
            if (k < 0) continue;
            int m = yen[0] * i + yen[1] * j + yen[2] * k;
            if (m == Y)
            {
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
    return 0;
}

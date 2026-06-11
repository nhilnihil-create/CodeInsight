#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> t(n+1), x(n+1), y(n+1);
    t[0] = 0, x[0] = 0, y[0] = 0;
    for (int i = 1; i <= n; ++i) scanf("%d %d %d", &t[i], &x[i], &y[i]);
    int dt, dr;
    for (int i = 0; i < n; ++i)
    {
        dt = t[i+1] - t[i];
        dr = abs(x[i+1] - x[i]) + abs(y[i+1] - y[i]);
        if ((dt & 1) == (dr & 1) && dt >= dr)
        {
            continue;
        }
        else
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}

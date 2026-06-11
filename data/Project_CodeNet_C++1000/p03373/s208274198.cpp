#define _USE_MATH_DEFINES
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<cmath>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ll long long
using namespace std;


int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int abmax = 2 * max(x, y);
    const int inf = 10000000000;
    int res = inf;
    rep(i, abmax + 1)
    {
        int cost = c * i + a * max(0, (x - i / 2)) + b * max(0, (y - i / 2));
        res = min(res, cost);
    }
    cout << res << endl;
}

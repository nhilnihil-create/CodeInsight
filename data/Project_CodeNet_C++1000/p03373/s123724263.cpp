#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, x, y, minCost;

    int cost = 0;

    cin >> a >> b >> c >> x >> y;

    if (a + b > c * 2)
    {
        minCost = c * 2;
    }
    else
    {
        minCost = a + b;
    }

    while (x > 0 && y > 0)
    {
        cost += minCost;
        x -= 1;
        y -= 1;
    }

    while (x > 0)
    {
        if (c * 2 < a)
        {
            cost += c * 2;
        }
        else
        {
            cost += a;
            x -= 1;
        }
    }
    while (y > 0)
    {
        if (c * 2 < b)
        {
            cost += c * 2;
            y -= 1;
        }
        else
        {
            cost += b;
            y -= 1;
        }
    }

    cout << cost;

    return 0;
}
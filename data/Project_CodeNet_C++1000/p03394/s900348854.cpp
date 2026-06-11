#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
#include <stack>
#include <bitset>
#include <set>
#include <chrono>
#include <string>
#include <assert.h>

using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if (n == 3)
    {
        cout << 2 << " " << 3 << " " << 25 << endl;
        return 0;
    }

    cout << 2 << " " << 3 << " " << 4 << " " << 9 << " ";

    n -= 4;

    int x = 8;

    while (n >= 2)
    {
        if (x + 2 > 30000)
            break;
        cout << x << " " << x + 2 << " ";
        x += 6;
        n -= 2;
    }

    x = 15;

    while (n >= 2)
    {
        if (x + 6 > 30000)
            break;
        cout << x << " " << x + 6 << " ";
        x += 12;
        n -= 2;
    }

    x = 6;

    while (n)
    {
        cout << x << " ";
        x += 6;
        n--;
    }

    cout << endl;

    return 0;
}
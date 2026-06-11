#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

int main()
{
    int A, B, C, X, Y;

    cin >> A >> B >> C >> X >> Y;

    int ab = 2 * C;

    int ans = 0;

    int min = INT32_MAX;

    for (int i = 0; i <= 100000; i++)
    {
        ans = i * ab;

        if (i < X)
            ans += A * (X - i);
        if (i < Y)
            ans += B * (Y - i);
        if (min > ans)
            min = ans;
    }

    cout << min << endl;

    return 0;
}
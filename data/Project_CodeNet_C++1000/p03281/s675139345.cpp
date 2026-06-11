#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, result = 0, counts = 0;

    cin >> n;

    if (n < 105)
    {
        cout << 0 << endl;
        return 0;
    }

    for (int j = 105; j <= n; j += 2)
    {

        for (int i = 1; i * i <= j; i++)
        {
            if ((j % i) == 0)
            {
                counts++;
                if ((j / i) != i)
                    counts++;
            }
        }
        if (counts == 8)
            result++;
        counts = 0;
    }

    cout << result << endl;
    return 0;
}
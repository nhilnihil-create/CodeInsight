#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, res = 1;
    cin >> x;

    for(int i = 2; i <= x; ++i)
    {
        int power = i * i;
        while(power <= x)
        {
            res = max(res, power);
            power *= i;
        }

    }

    cout << res << "\n";
    return 0;
}
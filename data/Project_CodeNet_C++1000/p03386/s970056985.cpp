#include <bits/stdc++.h>
using namespace std;

bool is_square(int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (i * i == n)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int a, b, k;
    cin >> a >> b >> k;
    for (int i = a; i <= b; i++)
    {
        if (i - a < k || b - i < k)
        {
            cout << i << endl;
        }
        /* code */
    }

    return 0;
}
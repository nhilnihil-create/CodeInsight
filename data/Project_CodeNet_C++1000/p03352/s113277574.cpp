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
    int x;
    cin >> x;
    int a[1001] = {0};
    a[1] = 1;
    for (size_t i = 2; i < 32; i++)
    {
        int b = i * i;
        a[b] = 1;
        while (b * i <= 1000)
        {
            b *= i;
            a[b] = 1;
        }
        /* code */
    }
    for (int i = x; i >= 1; i--)
    {
        if (a[i] == 1)
        {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}
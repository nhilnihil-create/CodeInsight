#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
    int d, n;
    cin >> d >> n;
    int a = 1;
    for (size_t i = 0; i < d; i++)
    {
        a *= 100;
    }
    if (n == 100)
    {
        cout << a * 101 << endl;
    }
    else
    {
        cout << a * n << endl;
    }

    return 0;
}
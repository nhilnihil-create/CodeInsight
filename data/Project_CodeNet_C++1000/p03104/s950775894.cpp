#include <bits/stdc++.h>
using namespace std;

int64_t from_zero(int64_t n)
{
    if (n % 4 == 0)
    {
        return n;
    }
    else if (n % 4 == 1)
    {
        return 1;
    }
    else if (n % 4 == 2)
    {
        return n ^ 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int64_t a, b;
    cin >> a >> b;
    int64_t res;
    if (a == 0)
    {
        res = from_zero(b);
    }
    else
    {
        res = from_zero(a - 1) ^ from_zero(b);
    }
    cout << res << endl;
}
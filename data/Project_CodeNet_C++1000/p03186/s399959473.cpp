#include <bits/stdc++.h>
using namespace std;

//create arrays outside of main()
int a[300000] = {};

int main()
{
    int a, b, c;

    cin >> a >> b >> c;

    int c_eaten;

    if (c < (a + b))
    {
        c_eaten = c;
    }
    else if (c == (a + b))
    {
        c_eaten = c;
    }
    else
    {
        c_eaten = a + b + 1;
    }

    cout << c_eaten + b;

    return 0;
}
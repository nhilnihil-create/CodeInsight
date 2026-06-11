#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char x[3];
    int p = 0;
    while (n)
    {
        x[p++] = n%10+'0';
        n /= 10;
    }
    for (int i = 0; i < 3; ++i)
    {
        if (x[i] == '1')
        {
            x[i] = '9';
        }
        else if (x[i] == '9')
        {
            x[i] = '1';
        }
    }
    for (int i = 2; i >= 0; --i)
    {
        putchar(x[i]);
    }
    puts("");
}

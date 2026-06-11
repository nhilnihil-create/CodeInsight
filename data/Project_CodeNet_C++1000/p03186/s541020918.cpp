#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    if(a + b + 1 >= c)
    {
        cout << b + c << "\n";
    }
    else
    {
        cout << (a + b + 1) + b << "\n";
    }

    return 0;
}
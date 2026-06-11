#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()
{
    long long int x,y;
    cin >> x >> y;
    if(x % y == 0)
    {
        cout << "-1\n";
    }
    else
    {
        cout << x << "\n";
    }

    return 0;
}
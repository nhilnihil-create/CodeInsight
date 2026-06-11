#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    if (x == y)
        cout << z;
    else if (x == z)
        cout << y;
    else
        cout << x;
}

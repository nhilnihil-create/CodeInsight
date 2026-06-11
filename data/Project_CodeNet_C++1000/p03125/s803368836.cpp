#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int x, y;
    cin >> x >> y;
    if(y % x == 0)
        cout << x + y;
    else
        cout << abs(y - x);
    return 0;
}
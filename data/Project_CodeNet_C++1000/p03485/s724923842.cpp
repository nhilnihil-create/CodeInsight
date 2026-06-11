#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int a,b,y;
    double x;
    cin >> a >> b;
    x = (a + b) / 2;
    if((a % 2 == 1 && b % 2 == 1) || (a % 2 == 0 && b % 2 == 0))
    {
        cout << x << endl;
    }
    else
    {
        y = (a + b) / 2;
        y++;
        cout << y << endl;
    }
    
}

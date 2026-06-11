#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()
{
    int a,b;
    cin >> a >> b;
    if(a + b == 15)
    {
        cout << "+\n";
    }
    else if(a * b == 15)
    {
        cout << "*\n";
    }
    else
    {
        cout << "x\n";
    }
    
    return 0;
}
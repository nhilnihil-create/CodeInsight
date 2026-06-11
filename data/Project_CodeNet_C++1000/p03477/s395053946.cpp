#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main()
{
    cin >> a >> b >> c >> d;
    int ab = a + b;
    int cd = c + d;
    if (ab > cd)
    {
        cout << "Left" << endl;
    }
    else if (ab < cd)
    {
        cout << "Right" << endl;
    }
    else
    {
        cout << "Balanced" << endl;
    }
    
    return 0;
}
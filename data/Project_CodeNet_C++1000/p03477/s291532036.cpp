#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int r,l;
    r = c + d;
    l = a + b;
    if(l > r)
    {
        cout << "Left" << endl;
    }
    else if(l == r)
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Right" << endl;
    }
    
}

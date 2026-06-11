
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int a;
    cin >> a;
    
    int b = a/100;
    int c = (a/10)%10;
    int d = a%10;
    
    if(b == 9)
    {
        b = 1;
    }
    else
    {
        b = 9;
    }
    if(c==1)
    {
        c = 9;
    }
    else
    {
        c= 1;
    }
    if(d==9)
    {
        d= 1;
    }
    else 
    {
        d = 9;
    }
    
    cout << b*100 + c*10 + d;
}

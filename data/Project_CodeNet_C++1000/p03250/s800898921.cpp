#include<cstdio>
#include<iostream>
#include <string>
#include<algorithm>
using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    
    int max= 0;
    
    if(a>max)
    {
        max = a;
    }
    if(b>max)
    {
        max = b;
    }
    if(c>max)
    {
        max = c;
    }
    
    if(max == a)
    {
        cout << a *10 + b + c;
    }
    else if(max == b)
    {
        cout << b*10 + c  + a;
    }
    else if(max == c)
    {
        cout << c*10 + a + b;
    }
}

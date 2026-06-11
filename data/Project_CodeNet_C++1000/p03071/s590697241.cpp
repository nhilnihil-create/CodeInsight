#include<cstdio>
#include<iostream>
#include <string>
#include<algorithm>
using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    
    if(a==b)
    {
        cout << a+b;
    }
    else if(a>b)
    {
        cout << a + a-1;
    }
    else if(b>a)
    {
        cout << b + b-1;
    }
    
    
}



#include<cstdio>
#include<iostream>
#include <string>
#include<algorithm>
using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    
    int c = ((a+b) % 2)*10;
    int d = (a+b) / 2;
    
    if(c>=5)
    {
        d = d + 1;
    }
    
    cout << d;
}



#include<cstdio>
#include<iostream>
#include <string>
#include<algorithm>
using namespace std;

int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    
    int min=1000,min1=1000;
    
    if(a<min)
    {
        min = a;
    }
    if(b<min)
    {
        min = b;
    }
    if(c<min1)
    {
        min1 = c;
    }
    if(d<min1)
    {
        min1 = d;
    }
    
    printf("%d",min+min1);
}



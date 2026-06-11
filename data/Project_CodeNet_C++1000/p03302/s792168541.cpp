#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        if(a+b==15)
            printf("+\n");
        else if(a*b==15)
            printf("*\n");
        else
            printf("x\n");
    }
    return 0;
}

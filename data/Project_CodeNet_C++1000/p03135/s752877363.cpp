#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    double t,x;
    cin >> t >> x;
    if(t>=1 && t<=100 && x>=1 && x<=100)
    {
        double result= t/x;
        printf("%.10lf\n",result);
    }
    return 0;
}

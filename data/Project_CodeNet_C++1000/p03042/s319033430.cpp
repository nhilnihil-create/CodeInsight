#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int l=n/100;
    int r=n%100;
    if(l>=1 && l<=12)
    {
        if(r>=1 && r<=12)
        cout<<"AMBIGUOUS";
        else
        cout<<"MMYY";
    }
    else
    {
        if(r>=1 && r<=12)
        cout<<"YYMM";
        else
        cout<<"NA";
    }
}
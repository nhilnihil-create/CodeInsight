#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if(a+b==15)
        return cout<<"+\n",0;
    else if(a*b==15)
        return cout<<"*\n",0;
    else
        return cout<<"x\n",0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    bool c=0;
    cin>>a>>b;
    if(a*b==15)
    {
        cout<<"*";
        c=1;
    }
    if(a+b==15)
    {
        cout<<"+";
        c=1;
    }
    if(c==0)
      cout<<"x";
    return 0;
}
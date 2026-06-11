#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y,r;
    cin>>x>>y;
    if(x>y)
        r=x;
    else if(y>x)
        r=y;
    else
        r=0;
    if(r!=0)
        cout<<r+r-1<<endl;
    else
        cout<<2*x<<endl;
}


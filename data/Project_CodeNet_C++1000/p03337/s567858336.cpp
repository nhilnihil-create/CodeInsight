#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,x,y,z,i,j;
    cin>>a>>b;
    x=a+b;
    y=a-b;
    z=a*b;

    i=max(x,y);
    j=max(y,z);
    cout<<max(i,j)<<endl;

    return 0;
}

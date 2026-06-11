#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c[3],d,e,z;
    cin>>a>>b;
    c[0]=a+b;
    c[1]=a-b;
    c[2]=a*b;
    z=c[0];
    for(d=1; d<3; d++)
    {
        if(z<=c[d])
    {
        z=c[d];
    }
    }



    cout<<z<<endl;
    return 0;
}

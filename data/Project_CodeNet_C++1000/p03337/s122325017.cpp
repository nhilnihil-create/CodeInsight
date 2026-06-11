#include<bits/stdc++.h>
using namespace std;

int main()
{
        int a,b,x=0,y=0,z;
        cin>>a>>b;
        x=a+b;
        y=a-b;
        z=a*b;
        cout<<max(x,max(y,z))<<endl;
        return 0;
}

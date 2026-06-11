#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int main()
{
    int n,a,b,x,y,z;
    cin>>n>>a>>b;
    x=max(a,b);
    y=min(a,b);
    z=x-y;

    if(z%2==0)
    {
        cout<<"Alice"<<endl;
    }
    else
        cout<<"Borys"<<endl;
        return 0;
}

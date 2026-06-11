#include <iostream>

using namespace std;

int main()
{
int x,y,z;
cin>>x>>y>>z;
if(x!=y&&y==z)cout<<x<<endl;
else if(y!=x&&x==z)cout<<y<<endl;
else if(z!=x&&x==y)cout<<z<<endl;
    return 0;
}
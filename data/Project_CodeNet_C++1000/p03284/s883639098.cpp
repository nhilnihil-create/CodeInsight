#include <iostream>

using namespace std;

int main()
{
    int x,y;
    cin>>x>>y;
   int z=x/y;
   int w=z*y;
  
  
   if((x-w)==0){cout<<0<<endl;}
else {cout<<1<<endl;}
    return 0;
}

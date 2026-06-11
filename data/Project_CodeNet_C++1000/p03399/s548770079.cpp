#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
   int a,c,x,z;
   cin>>a>>c>>x>>z;
   int d=min({a,c});
   int y=min({x,z});
   cout<<d+y;
}

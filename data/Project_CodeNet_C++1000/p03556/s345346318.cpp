#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    int n,y,p;
    cin>>n;
    for(int i=n;i>=0;i--)
   {
    y=sqrt(i);
    p=y*y;
    if(p==i)
    {
        cout<<p;
        break;
    }
   }

    return 0;
}

#include <iostream>
#include <stdlib.h>
//#include <string.h>

using namespace std;

int main()
{
    long x,d,r,i=10;
    cin>>r>>d>>x;
    while(i--)
    {
        x=r*x-d;
        cout<<x<<endl;
    }

    return 0;
}

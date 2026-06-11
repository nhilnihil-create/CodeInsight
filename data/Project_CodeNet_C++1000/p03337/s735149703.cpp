#include <iostream>
#include <cmath>

using namespace std;

int main()
{
     int a,b,c;
    cin>>a>>b;
    c= max(a+b,a-b);
     cout<<max (c,a*b);

    return 0;
}

#include <cmath>
#include <iostream>
using namespace std;
int main()
{
int b,c;
cin>>b>>c;
if (c%b==0)
    cout<<b+c;
else
    cout<<c-b;

    return 0;
}

#include<iostream>
using namespace std;
int main ()
{
    int a,b;
    cin>>a>>b;
    int z=b/2;
    (a>=6&&a<=12)?cout<<z:
    (a>=13)?cout<<b:
    cout<<"0";
    return 0;
}

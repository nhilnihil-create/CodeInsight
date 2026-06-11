#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if ((fmax(a,c)-fmin(a,c)<=d) || (fmax(b,c)-fmin(b,c)<=d && fmax(a,b)-fmin(a,b)<=d)) cout<<"Yes";
    else cout<<"No";
}
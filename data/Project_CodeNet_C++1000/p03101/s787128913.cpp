#include <iostream>

using namespace std;

int main()
{
    int h,w,a,b;
    cin>>h>>w>>a>>b;
    cout<<(h*w)-(a*w+b*h)+(a*b);
}
#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b;
    c=a%500;
    if(c>b)
        cout<<"No";
    else
    {
        cout<<"Yes";
    }
    return 0;
}

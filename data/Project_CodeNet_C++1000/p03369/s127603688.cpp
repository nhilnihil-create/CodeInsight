#include <iostream>
using namespace std;
int main()
{
    int c=0;
    char a[3];
    cin>>a;
    for (int i=0;i<3;i++)
    {
        if (a[i]=='o') c+=100;
    }
    cout<<700+c;
}

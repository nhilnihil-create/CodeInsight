#include <iostream>
using namespace std;
int main()
{
    char c[10];
    for (int i=1; i<=9; i++)
    {
        cin>>c[i];
    }
    cout<<c[1]<<c[5]<<c[9];
    return 0;
}
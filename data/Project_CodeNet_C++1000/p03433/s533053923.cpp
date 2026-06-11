#include <iostream>
//#include <stdlib.h>
//#include <string.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n;
    cin>>m;
    n=n%500;
    if(n>m)
        cout<<"No";
    else
        cout<<"Yes";

    return 0;
}

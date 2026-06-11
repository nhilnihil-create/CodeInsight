#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[3];
    char b[3];
    char c[3];
    for(int i=1;i<=3;i++)
    {
        cin>>a[i];
    }
    for(int j=1;j<=3;j++)
    {
        cin>>b[j];
    }
    for(int m=1;m<=3;m++)
    {
        cin>>c[m];
    }
    cout<<a[1]<<b[2]<<c[3];
    return 0;
}
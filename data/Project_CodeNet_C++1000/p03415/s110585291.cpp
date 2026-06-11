#include <bits/stdc++.h>
using namespace std;


int main()
{
    long long x,y,i,t,s,j;
    char a[4][4];
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<a[0][0]<<a[1][1]<<a[2][2];
    return 0;
}

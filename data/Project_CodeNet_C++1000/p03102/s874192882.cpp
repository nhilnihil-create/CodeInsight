#include <iostream>
#include <stdlib.h>
//#include <string.h>

using namespace std;

int main()
{
    long n,m,a[29][29],b[50],i,j,c,sum,count=0;
    cin>>n>>m>>c;
    for(i=0;i<m;i++)
        cin>>b[i];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            cin>>a[i][j];
    }


    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=0;j<m;j++)
        {
            sum=sum+a[i][j]*b[j];
        }
        if((sum+c)>0)
            count++;
    }
    cout<<count;

    return 0;
}

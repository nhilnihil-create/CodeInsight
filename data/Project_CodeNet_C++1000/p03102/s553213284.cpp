#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,c,i,j,a[101],b[101],count=0;
    cin>>n>>m>>c;
    for(i=0; i<m; i++)
    {
        cin>>b[i];
    }
    for(i=0; i<n; i++)
    {
        int sum=0;
        for(j=0; j<m; j++)
        {
            cin>>a[j];
            sum+=a[j]*b[j];
        }
        if(sum+c>0)
        {
            count++;
        }

    }
    cout<<count;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j,k,x,cnt=0;
    cin>>n>>m;
    int ara[m+1];
    memset(ara,0,sizeof ara);
    for(i=0;i<n;i++)
    {
        cin>>k;
        for(j=0;j<k;j++)
        {
            cin>>x;
            ara[x]++;
        }
    }
    for(i=0;i<=m;i++)
    {
        if(ara[i]==n)
            cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}

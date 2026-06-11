#include<bits/stdc++.h>
using namespace std;
int vis[200005];
int main()
{
    int n,m,i,j,a[200005];
    memset(vis,0,sizeof(vis));
    cin>>n;
    int cnt=1;
    while(1)
    {
        if(vis[n]==1)
        {
            cout<<cnt<<endl;
            break;
        }
        else vis[n]=1;
        if(n%2==0)
        {
            n=n/2;
        }
        else n=3*n+1;
        cnt++;
    }
    return 0;
}


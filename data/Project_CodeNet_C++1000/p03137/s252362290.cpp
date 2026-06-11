#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i;
    cin>>n>>m;
    int ara[m],dis[m-1];
    for(i=0;i<m;i++)
        cin>>ara[i];
    sort(ara,ara+m);
    for(i=1;i<m;i++)
    {
        dis[i-1]=ara[i]-ara[i-1];
    }
    sort(dis,dis+m-1);
    int res=0;
    n--;
    for(i=m-2;i>=0;i--)
    {
        if(n==0)
           res+=dis[i];
        else
            n--;
    }
    cout<<res<<endl;
    return 0;
}

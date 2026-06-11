#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,c;
    cin>>n>>m>>c;
    int ara[m],cnt=0,i,x;
    for(i=0;i<m;i++)
        cin>>ara[i];
    while(n--)
    {
        int sum=c;
        for(i=0;i<m;i++)
        {
            cin>>x;
            sum+=(x*ara[i]);
        }
        if(sum>0)cnt++;
    }
    cout<<cnt;
}

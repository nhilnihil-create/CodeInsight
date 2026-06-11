#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ara[5],i,x,y,n;
    for(i=0;i<5;i++)
        cin>>ara[i];
    int sum=0,mx=0,p=0,q=0;
    for(i=0;i<5;i++)
    {
        x=ceil(ara[i]/10.0);
        y=(x*10);
        sum+=y;
        if((y-ara[i])>mx)
        {
            mx=y-ara[i];
            p=ara[i];
            q=y;
        }
    }
    cout<<(sum-q+p)<<endl;
    return 0;
}

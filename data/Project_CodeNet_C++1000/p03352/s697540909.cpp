#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,i,b,a[1000]={0};
    cin>>x;
    a[1]=1;
    for(i=2;i<=x;i++)
    {
        b=i*i;
        while(b<=x)
        {
            a[b]=1;
            b*=i;
        }
    }
    for(i=x;i>=0;i--)
    {
        if(a[i]==1)
        {
            cout<<i<<endl;
            return 0;
        }
    }
}

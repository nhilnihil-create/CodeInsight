#include<bits/stdc++.h>

using namespace std;


int main()
{
    long long t,b,c,d,n,m,i,x,y,j;
    cin>>n>>m;
    c=0;
    int a[6];

    for(i=n;i<=m;i++)
    {
        x=i;
        j=0;
        while(x)
        {
            a[j++]=x%10;
            x/=10;

        }
        if(a[0]==a[4]&&a[1]==a[3])
        {
            c++;
        }

    }
    cout<<c;
    return 0;
}

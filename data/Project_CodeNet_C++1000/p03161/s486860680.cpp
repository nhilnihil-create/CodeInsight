#include<bits/stdc++.h>
using namespace std;
long long int f[1000006];
long long int a[1000006];
int main()
{

    long long int mod,t,k=0,i,m,n,x,j=0,l,c=0,r=0,w,s,d=0,sum=0,mul,mx1,mx,s1=10000000,s2=0;

    cin>>n>>k;


    for(i=1; i<=n; i++)
    {

        cin>>a[i];
    }


    for(i=n-1; i>=1; i--)
    {
        f[i]=1e9;
        for(j=1; j<=k; j++)
        {
            if(i+j<=n)
            {
                f[i]=min( f[i],f[i+j]+abs(a[i]-a[i+j]));
            }

        }

    }
    cout<<f[1]<<endl;
    return 0;

}

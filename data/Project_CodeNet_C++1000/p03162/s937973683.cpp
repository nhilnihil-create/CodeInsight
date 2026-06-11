#include<bits/stdc++.h>
using namespace std;
long long int f[100005][3];
long long int a[100006],a1[100005],a2[100005];
int main()
{

    long long int mod,t,k=0,i,m,n,x,j=0,l,c=0,r=0,w,s,d=0,sum=0,mul,mx1,mx,s1=10000000,s2=0;

    cin>>n;


    for(i=1; i<=n; i++)
    {

        cin>>a[i]>>a1[i]>>a2[i];
    }
f[n+1][0]=f[n+1][1]=f[n+1][2]=0;


    for(i=n; i>=1; i--)
    {


    f[i][0]=max((a1[i]+f[i+1][1]),(a2[i]+f[i+1][2]));
    f[i][1]=max((a[i]+f[i+1][0]),(a2[i]+f[i+1][2]));
    f[i][2]=max((a1[i]+f[i+1][1]),(a[i]+f[i+1][0]));

    }

    d=max(max(f[1][0],f[1][1]),f[1][2]);

    cout<<d<<endl;
    return 0;

}

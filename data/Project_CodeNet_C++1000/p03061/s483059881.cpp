#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int f[N],b[N],ara[N];
int main()
{
    int n,res;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>ara[i];
    f[0]=ara[0],b[n-1]=ara[n-1];
    for(int i=1;i<n;i++)
        f[i]=__gcd(ara[i],f[i-1]);

    for(int i=n-1;i>=0;i--)
        b[i]=__gcd(ara[i],b[i+1]);

    res=0;
    for(int i=0;i<n;i++)
    {
        if(i==0) res=b[1];
        if(i==(n-1))res=max(res,f[n-2]);
        res=max(res,__gcd(f[i-1],b[i+1]));
    }
    cout<<res<<endl;
    return 0;
}

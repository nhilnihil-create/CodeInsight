#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int a[10];
int go(int i,int n)
{
    int s=0;
    for(;i<=n;i++)
    {
        s+=a[i];
    }
    return s;
}
int main()
{
    ft
    int i,j,k,n,l,x,y,z;
    cin>>n>>x>>y>>z;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int ans=INT_MAX;
    do
    {
        for(i=0;i<n-2;i++)
        {
            for(j=i+1;j<n-1;j++)
            {
                for(k=j+1;k<n;k++)
                {
                    int s=0;
                    l=i*10+abs(go(0,i)-x);
                    s+=l;
                    l=(j-i-1)*10+abs(go(i+1,j)-y);
                    s+=l;
                    l=(k-j-1)*10+abs(go(j+1,k)-z);
                    s+=l;
                    ans=min(ans,s);
                }
            }
        }
    }while(next_permutation(a,a+n));
    cout<<ans<<"\n";
    return 0;
}
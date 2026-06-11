#include<bits/stdc++.h>
using namespace std;
    int n,m,l,r;
    long long ans,k,a[200010]={};
int main()
{
    cin >> n;
    for (int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    l=1;r=2;
    k=a[l];
    ans=0;
    while (r<=n)
    {
        if ((k^a[r])==k+a[r])
        {
            k+=a[r];
            r++;
        }
        else
        {
            k-=a[l];
            ans+=(r-l);
            l++;
        }
    }
    m=r-l;
    for (;m>=0;m--)
        ans+=m;
    cout << ans << endl;
}

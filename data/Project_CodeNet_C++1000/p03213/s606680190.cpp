#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
ll a[105];
int main()
{
    ft
    ll t,i,j,n,m,l,r,s=0,x=0,y=0,z=0;
    cin>>n;
    for(l=2; l<=n; l++)
    {
        r=l;
        for(i=2; i<=(r/i); i++)
        {
            while(r%i==0)
            {
                r/=i;
                a[i]++;
            }
        }
        if(r>1)
        {
            a[r]++;
        }
    }
    l=0,r=0;
    for(i=2; i<=n; i++)
    {
        if(a[i]>=74)
        {
            z++;
        }
        if(a[i]>=24)
        {
            x++;
        }
        if(a[i]>=14)
        {
            y++;
        }
        if(a[i]>3)
        {
            r++;
        }
        if(a[i]>1)
        {
            l++;
        }
    }
    s=z+x*(l-1)+y*(r-1)+(r*(r-1)*(l-2))/2;
    cout<<s<<"\n";
    return 0;
}
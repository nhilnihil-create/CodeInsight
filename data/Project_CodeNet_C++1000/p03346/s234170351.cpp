#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x,y) memset(x,y,sizeof(x))

ll num[2000005],cont[200005];

int main()
{
    ios_base:: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    ll i,j,k,s,d,r,m,n;
    cin>>n;
    for(i=1; i<=n; i++) cin>>r, num[r]=i;

    m=1; d=1;
    for(i=2; i<=n; i++)
    {
        if(num[i]>num[i-1]) d++, m = max(m, d);
        else d=1;
    }
    cout<<n-m<<endl;
}



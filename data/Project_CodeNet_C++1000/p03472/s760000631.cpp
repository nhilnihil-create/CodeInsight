#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,h;cin>>n>>h;

    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i]>>b[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int l=-1,r=n;
    for(int m=l+(r-l)/2;m!=l;m=l+(r-l)/2)
    {
        if(a[n-1]<b[m])r=m;
        else l=m;
    }

    int ans=0;
    for(int i=n-1;i>l&&h>0;i--,ans++)h-=b[i];

    if(h>0)ans+=(h-1)/a[n-1]+1;

    cout<<ans<<"\n";

    return 0;
}

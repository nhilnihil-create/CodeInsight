#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,h;cin>>n>>h;

    vector<int> a(n),b(n);
    int maxa=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        maxa=max(maxa,a[i]);
    }

    sort(b.begin(),b.end(),greater<int>());

    int ans=0;

    for(int i=0;i<n;i++)
    {
        if(h<=0)break;
        if(b[i]<maxa)break;
        h-=b[i];
        ans++;
    }

    if(h>0)
    {
        ans+=(h-1)/maxa+1;
    }

    cout<<ans<<"\n";

    return 0;
}

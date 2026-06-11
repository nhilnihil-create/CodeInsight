#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=100000+5;

int n,v[N];

/// bag AIB

int aib[2*N];

inline void add(int poz,int x)
{
    poz+=N;
    for(int i=poz;i<2*N;i+=i&(-i))
        aib[i]+=x;
}

inline int prefix(int poz)
{
    poz+=N;
    int ans=0;
    for(int i=poz;i>=1;i-=i&(-i))
        ans+=aib[i];
    return ans;
}

inline ll cate(int x)
{
    for(int i=0;i<2*N;i++) aib[i]=0;
    ll ans=0;
    add(0,1);
    int pr=0,mi=0;
    for(int i=1;i<=n;i++)
    {
        if(v[i]>=x) pr++;
        else pr--;
        int cur=prefix(pr);
        ans+=cur;
        add(pr,1);
    }
    return ans;
}

int lo=1,hi=1,ans=0;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        hi=max(hi,v[i]);
    }
    ll total=(ll)n*(n+1)/2;
    ll jum=(total+1)/2;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        ll cnt=cate(mid);
        if(cnt>=jum)
        {
            ans=mid;
            lo=mid+1;
        }
        else
            hi=mid-1;
    }
    cout<<ans<<"\n";
    return 0;
}

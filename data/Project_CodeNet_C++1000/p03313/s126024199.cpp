#include <bits/stdc++.h>

using namespace std;
const int N=5e5+5,mod=1e9+7;
#define ll long long
int a[N];
pair<int,int> Best[N];
void update(pair<int,int> &p,int idx)
{
    if(a[idx]>a[p.first]) swap(idx,p.first);
    if(a[idx]>a[p.second]&&idx!=p.first) swap(idx,p.second);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<(1<<n);i++)
    {
        cin>>a[i];
        pair<int,int>p={1<<n,1<<n};
        for(int j=0;j<n;j++)
        {
            int t=(1<<j);
            t=(~t);
            t=(i&t);
            if(t==i) continue;
            update(p,Best[t].first);
            update(p,Best[t].second);
        }
        update(p,i);
        Best[i]=p;
    }
    int ans=0;
    for(int i=1;i<(1<<n);i++)
    {
        ans=max(ans,a[Best[i].first]+a[Best[i].second]);
        cout<<ans<<'\n';
    }
    return 0;
}

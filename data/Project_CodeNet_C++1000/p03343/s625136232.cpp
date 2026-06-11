#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,k,q,a[N],b[N];
int solve(int x)
{
    vector<int>v;
    vector<int>res;
    for(int i=1;i<=n;i++)
        if(a[i]>=x) v.push_back(a[i]);
    else
    {
        sort(v.begin(),v.end());
        for(int i=0;i+k<=v.size();i++)
            res.push_back(v[i]);
        v.clear();
    }
    sort(v.begin(),v.end());
    for(int i=0;i+k<=v.size();i++)
        res.push_back(v[i]);
    v.clear();
    sort(res.begin(),res.end());
    if(res.size()<q) return 1e9;
    return res[q-1]-res[0];
}
int main()
{
    scanf("%d%d%d",&n,&k,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),b[i]=a[i];
    sort(b+1,b+1+n);
    int tot=unique(b+1,b+1+n)-b-1;
    int ans=1e9;
    for(int i=1;i<=tot;i++)
        ans=min(ans,solve(b[i]));
    printf("%d\n",ans);
}
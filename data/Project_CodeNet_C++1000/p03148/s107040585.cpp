#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N=1e5+5;
 
int n, k, best=0, ans=0;
int t[N], d[N], f[N];
set<int> types;
multiset<pair<int, int> > removable;
pair<int, int> a[N];
 
int32_t main()
{
    IOS;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>t[i]>>d[i];
        a[i].first=d[i];
        a[i].second=t[i];
    }
    sort(a+1, a+n+1);
    reverse(a+1, a+n+1);
    for(int i=1;i<=k;i++)
    {
        removable.insert({a[i].first, a[i].second});
        f[a[i].second]++;
        ans+=a[i].first;
        types.insert(a[i].second);
    }
    int sz=types.size();
    best=ans + sz*sz;
    for(int i=k+1;i<=n;i++)
    {
        if(types.find(a[i].second)!=types.end())
            continue;
        if(!removable.size())
            break;
        bool check=0;
        while(removable.size())
        {
            auto it=*removable.begin();
            if(f[it.second]==1)
                removable.erase(removable.find(it));
            else
            {
                check=1;
                ans-=it.first;
                f[it.second]--;
                removable.erase(removable.find(it));
                break;
            }
        }
        if(!check)
            break;
        ans+=a[i].first;
        f[a[i].second]++;
        types.insert(a[i].second);
        sz++;
        best=max(best, ans + sz*sz);
    }
    cout<<best;
    return 0;
}
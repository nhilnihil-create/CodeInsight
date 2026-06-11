//InTheNameOfGod
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define rep(i,j,k) for(int i=j;i<k;++i)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define pb push_back
#define lb(i) i&(-i);
#define int ll
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn =1e5+5;
set<pair<int,int> > rs,ls;
int n,l[maxn],r[maxn],ans,x;
void er(int u)
{
    ls.erase({l[u],u});
    rs.erase({r[u],u});
}
int chk(int t)
{
    if(rs.size()==0)return 0;
    int re=0;
    pair<int,int> p,q;
    p=*rs.begin();
    q=*ls.rbegin();
    if(t==0)
    {
        if(q.first<=x)return 0;
        re+=abs(x-q.first);
        er(q.second);
        x=q.first;
        return re+chk(t^1);
    }
    else
    {
        if(p.first>=x)return 0;
        re+=abs(x-p.first);
        er(p.second);
        x=p.first;
        return re+chk(t^1);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    rep(i,0,n)
    {
        cin>>l[i]>>r[i];
        rs.insert({r[i],i});
        ls.insert({l[i],i});
    }
    x=0;
    int s=chk(0);
    ans=max(ans,s+abs(x));
    x=0;
    rep(i,0,n)
    {
        rs.insert({r[i],i});
        ls.insert({l[i],i});
    }
    s=chk(1);
    ans=max(ans,s+abs(x));
    cout<<ans;
    return 0;
}
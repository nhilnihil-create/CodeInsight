#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ll          long long
#define pb          push_back
#define INF         9223372036854775807
#define    endl        '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define lower(u)    transform(u.begin(), u.end(), u.begin(), ::tolower);//convert string u to lowercase;
#define upper(u)    transform(u.begin(), u.end(), u.begin(), ::toupper);
using namespace std;

using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define N  200005



ll n,l,r;
vi a(N),seg(4*N);
void build(ll cur,ll st,ll end)
{
    if(st==end)
    {
        seg[cur]=a[st];
        return;
    }
    ll mid=(st+end)>>1;
    build(2*cur,st,mid);
    build(2*cur+1,mid+1,end);
    seg[cur]=max(seg[2*cur],seg[2*cur+1]);    /*  1-change here  */
}
ll query(ll cur,ll st,ll end,ll l,ll r)
{
    if(l<=st&&r>=end)
    return seg[cur];
    if(r<st||l>end)
    return 0;                           /*  2-change here  */
    ll mid=(st+end)>>1;
    ll ans1=query(2*cur,st,mid,l,r);
    ll ans2=query(2*cur+1,mid+1,end,l,r);
    return max(ans1,ans2);                 /*  3-change here  */
}
void update(ll cur,ll st,ll end,ll pos,ll upd)
{
    if(st==end)
    {
        a[pos]=upd;                    /*  4-change here  */
        seg[cur]=upd;                    /*  5-change here  */
        return;
    }
    ll mid=(st+end)>>1;
    if(st<=pos&&pos<=mid)
        update(2*cur,st,mid,pos,upd);
    else
        update(2*cur+1,mid+1,end,pos,upd);
    seg[cur]=max(seg[2*cur],seg[2*cur+1]);    /*  6-change here  */
}
void solve()
{
    cin>>n;
    ll h[n+1],x[n+1];
    rep(i,1,n+1)cin>>h[i];
    rep(i,1,n+1)cin>>x[i];
    build(1,1,n);
    ll ans=0;
    rep(i,1,n+1)
    {
        ll v=query(1,1,n,0,h[i]-1);
        ans=max(ans,v+x[i]);
        update(1,1,n,h[i],v+x[i]);
    }
    // rep(i,1,n+1)
    //     cout<<a[i]<<" ";
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int TESTS=1;
//    cin>>TESTS;
    while(TESTS--)
    {
        solve();
    }
    return 0;
}
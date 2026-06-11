/* ****mittal21**** */
#include<bits/stdc++.h>
#define ll          long long int 
#define ld          long double
#define pb          push_back
#define endl        '\n'
#define pii         pair<long long int,long long int>
#define vi          vector<ll>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll )x.size()
#define hell        1000000007
#define jell        998244353
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define repr(i,a,b)   for(ll int i=a;i>=b;i--)
#define lbnd    lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define DEC(N)  cout << std::fixed; cout << setprecision(N);
using namespace std;
#define N  200005
vi a(N),seg(4*N);
ll hei[N],cost[N];
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
  seg[cur]=max(seg[2*cur],seg[2*cur+1]);  /*  1-change here  */
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
  return (max(ans1,ans2));                 /*  3-change here  */
}
void update(ll cur,ll st,ll end,ll pos,ll upd)
{
  if(st==end)
  {
    a[pos]+=upd;          /*  4-change here  */
    seg[cur]+=upd;          /*  5-change here  */
    return;
  }
  ll mid=(st+end)>>1;
  if(st<=pos&&pos<=mid)
    update(2*cur,st,mid,pos,upd);
  else
    update(2*cur+1,mid+1,end,pos,upd);
  seg[cur]=max(seg[2*cur],seg[2*cur+1]);  /*  6-change here  */
}
void solve()
{
   ll n;
   cin>>n;
   for(int i=1;i<=n;i++)
    cin>>hei[i];
   for(int i=1;i<=n;i++)
   {
      cin>>cost[i];
   }
   build(1,1,n);
   for(int i=1;i<=n;i++)
   {
       ll op=query(1,1,n,1,hei[i]-1);
        ll oi=max(op+cost[i],a[hei[i]]);
       update(1,1,n,hei[i],oi);
   }
   cout<<query(1,1,n,1,n);
   return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll testcase=1;
    //cin>>testcase;
    while(testcase--)
    {
        solve();
    }
    return 0;
}
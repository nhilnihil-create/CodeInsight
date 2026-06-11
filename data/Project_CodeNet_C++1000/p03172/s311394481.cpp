#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef int                sint;
#define int                long long
#define ll                 long long
#define endl               '\n'
#define PI                 3.14159265358979323846
#define all0(a)            memset(a,0,sizeof(a))
#define all1(a)            memset(a,-1,sizeof(a))
#define all(v)             v.begin(),v.end()
#define rep(i,a,b)         for(int i=a;i<b;i++)
#define repr(i,a,b)        for(int i=a-1;i>=b;i--)
#define lc(x)              x<<1
#define rc(x)              x<<1|1
#define tm                 (tl+tr)/2
#define pb                 push_back
#define bpc(a)             __builtin_popcount(a)
#define x                  first
#define y                  second
#define xx                 first.first
#define xy                 first.second
#define yx                 second.first
#define yy                 second.second
#define sz(n)              (int)(n.size())
#define min3(a,b,c)        min(a,min(b,c))
#define max3(a,b,c)        max(a,max(b,c))
#define IOS                ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define hell               1000000007
#define dec(a)             fixed<<setprecision(a)
#define MAXN               (sint)(1e5+9)

inline int mod(int x,int p = hell) {return (x < 0?(x%p)+p:x%p);}

int ans[MAXN];

int seg[MAXN<<2];

void dolazy(int v)
{
  seg[lc(v)] += seg[v];
  seg[lc(v)] %= hell;
  seg[rc(v)] += seg[v];
  seg[rc(v)] %= hell;
  seg[v] = 0;
}

void update(int v,int tl,int tr,int l,int r,int x)
{
  if(l > r) return;
  if(tl == l && tr == r)
  {
    seg[v] += x;
    seg[v] %= hell;
    return;
  }
  dolazy(v);
  update(lc(v),tl,tm,l,min(r,tm),x);
  update(rc(v),tm+1,tr,max(l,tm+1),r,x);
}

void pushdown(int v, int tl, int tr)
{
  if(tl == tr)
  {
    ans[tl] += seg[v];
    ans[tl] %= hell;
    seg[v] = 0;
    return;
  }
  dolazy(v);
  pushdown(lc(v), tl, tm);
  pushdown(rc(v), tm+1, tr);
}


int solve()
{
  int n,k;
  cin>>n>>k;
  int a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  ans[0] = 1;
  for(int i=0;i<n;i++)
  {
    if(a[i] == 0)
      continue;
    for(int j=0;j<=k;j++)
    {
      update(1, 0, k, j+1, min(j+a[i], k), ans[j]);
    }
    pushdown(1, 0, k);
  }
  cout<<ans[k]<<endl;
  return 0;
}

signed main()
{
  IOS;
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  int tc=1;
  // cin>>tc;
  for(int i=1;i<=tc;i++)
  {
    solve();
  }
  return 0;
}
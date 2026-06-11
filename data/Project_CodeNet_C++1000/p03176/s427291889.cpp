#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define all(a) (a).begin(),(a).end()
#define X first
#define Y second
#define inf 1e18+5
using namespace std;
const int N=2e5+5;
int h[N],a[N];
int seg[4*N];
void update(int t,int l,int r,int idx,int val)
{
    if(l==r)
    {
        seg[t]=max(seg[t],val);
        return;
    }
    int mid=(l+r)/2;
    if(idx<=mid)update(2*t+1,l,mid,idx,val);
    else update(2*t+2,mid+1,r,idx,val);
    seg[t]=max(seg[2*t+1],seg[2*t+2]);
    return;
}
int query(int t,int l,int r,int c,int d)
{
    if(r<c||l>d)return 0;
    if(l>=c&&r<=d)return seg[t];
    int mid=(l+r)/2;
    int q1=query(2*t+1,l,mid,c,d);
    int q2=query(2*t+2,mid+1,r,c,d);
    return max(q1,q2);
}
void solve()
{
  int n,ans=0; cin>>n;
  for(int i=0;i<n;i++){cin>>h[i]; h[i]--;}
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n;i++)
  {
      int q=0;
      if(h[i])q=query(0,0,n-1,0,h[i]-1);
      ans=max(ans,a[i]+q);
      update(0,0,n-1,h[i],a[i]+q);
  }
  cout<<ans;
  return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--)solve();
    return 0;
}

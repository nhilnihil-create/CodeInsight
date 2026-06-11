#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

map<int,int>mm;
int val[100005];
int fi[100005];
int seg[800050];
int temp[200020];

void build(int ver,int tl,int tr)
{
  if(tl>tr)
    return ;
  else if(tl==tr)
    seg[ver]=temp[tl];
  else
  {
    int tm=(tl+tr)/2;
    build(2*ver,tl,tm);
    build(2*ver+1,tm+1,tr);
    seg[ver]=seg[2*ver]+seg[2*ver+1];
  }  
}

void upd(int ver,int tl,int tr,int pos,int val)
{
  if(tl>tr)
    return ;
  else if(tl==tr)
    seg[ver]+=val;
  else
  {
    int tm=(tl+tr)/2;
    if(tm>=pos)
      upd(2*ver,tl,tm,pos,val);
    else
      upd(2*ver+1,tm+1,tr,pos,val);
    seg[ver]=seg[2*ver]+seg[2*ver+1];
  }  
}

int get(int ver,int tl,int tr,int l,int r)
{
  if(tl>tr||l>r||tr<l||r<tl)
    return 0;
  else if(tl==l&&tr==r)
    return seg[ver];
  else
  {
    int tm=(tl+tr)/2;
    return get(2*ver,tl,tm,l,min(tm,r))+get(2*ver+1,tm+1,tr,max(tm+1,l),r);
  }  
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);  
  cout.tie(0);   

  #ifndef ONLINE_JUDGE
      if(fopen("INPUT.txt","r"))
      {
      freopen ("INPUT.txt" , "r" , stdin);
      freopen ("OUTPUT.txt" , "w" , stdout);
      }
  #endif  

  int n;
  cin>>n;
  int a[n+1];
  set<int>s;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
    s.insert(a[i]);
  }
  int cnt=0;
  for(auto i:s)
  {
    mm[i]=++cnt;
    val[cnt]=i;
  }
  for(int i=1;i<=n;i++)
    a[i]=mm[a[i]];    

  vector<int>v;
  for(auto i:s)
    v.push_back(mm[i]);
  int l=0,r=v.size();
  r--;
  int len=(n*(n+1))/2;
  int mx=0;
  while (l<=r)
  {
    int mid=l+(r-l)/2;
    int ind=v[mid];
    int lim=1e5+1;
    for(int i=0;i<=800010;i++)
      seg[i]=0;
    for(int i=0;i<=200005;i++)
      temp[i]=0;
    int x=lim;
    for(int i=1;i<=n;i++)
    {
      if(a[i]<ind)
        x--;
      else
        x++;
      temp[x]++;
    }
    build(1,1,2*lim);
    x=0;
    int tot=0;
    for(int i=1;i<=n;i++)
    {
      int z=x+lim;
      int num=get(1,1,2*lim,z,2*lim);
      if(a[i]<ind)
        x--;
      else
        x++;
      tot+=num;
      upd(1,1,2*lim,x+lim,-1);
    }
    if(tot>=(len+1)/2)
    {
      l=mid+1;
      mx=max(mx,ind);
    }
    else
    {
      r=mid-1;
    }    
  }
  cout<<val[mx];

}

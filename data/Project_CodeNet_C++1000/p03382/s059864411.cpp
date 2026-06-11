#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
const int N=1e5+10;
int a[N],b[N];
int32_t main()
{
  #ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
  freopen("out","w",stdout);
  #endif 
  int n;
  cin>>n;
  for(int i=0;i<n;i++){cin>>a[i];b[i]=a[i];}

  int mx=max_element(a,a+n)-a;
  int nn=a[mx];
  int half=nn/2;
  for(int i=0;i<n;i++)
  {
    if(i==mx)continue;
    if(b[i]>half)b[i]=nn-b[i];
  }
  int r=0;int dist=half-b[0];
  if(0==mx){r=1;dist=half-b[1];}

  for(int i=0;i<n;i++)
  {
    if(i==mx)continue;
    if(half-b[i]<dist){dist=half-b[i];r=i;}
  }
  cout<<nn<<" "<<a[r];
  
 
}
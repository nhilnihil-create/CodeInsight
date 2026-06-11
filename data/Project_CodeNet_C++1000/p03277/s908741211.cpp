#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+50;
inline int gi() {
  char ch=getchar(); int q=0,x=0;
  while(ch<'0'||ch>'9') q=(ch=='-'?1:q),ch=getchar();
  while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
  return q?(-x):x;
}
int a[N],f[N],P;
void ins(int x){
  while(x<=P)
    ++f[x],x+=x&-x;
  return;
}
int qry(int x){
  if (x<=0) return 0;
  int s=0;
  while(x)
    s+=f[x],x-=x&-x;
  return s;
}
int main(){
  int n=gi(),l=0,r=0,mid;
  for (int i=1; i<=n; ++i) a[i]=gi(),r=max(r,a[i]);
  ll ans,sum=1ll*n*(n+1)/2-1ll*n*(n+1)/4; P=2*n;
  while(l<=r){
    mid=(l+r)>>1,ans=0;
    memset(f,0,sizeof(f));
    int num=0;
    for (int i=1; i<=n; ++i){
      ins(num+n);
      if (a[i]>=mid) ++num;
      else --num;
      ans+=qry(num+n);
    }
    if (ans>=sum) l=mid+1;
    else r=mid-1;
  }
  cout<<r;
  return 0;
}
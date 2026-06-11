#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N=200005;
int a[N],b[N],c[N],d[N];
int n,ans=0;
int pows=1;
int main() {
  scanf("%d",&n);
  for (int i=1;i<=n;++i) scanf("%d",&a[i]);
  for (int i=1;i<=n;++i) scanf("%d",&b[i]);
  for (int i=0;i<=28;++i) {
    for (int j=1;j<=n;++j) {
      c[j]=a[j];
      d[j]=b[j];
      c[j]%=(pows<<1);
      d[j]%=(pows<<1);
    }
    int sum=0;
    sort(c+1,c+1+n);sort(d+1,d+1+n);
    for (int j=1;j<=n;++j) {
      sum+=(lower_bound(d+1,d+1+n,2*pows-c[j])-d)-(lower_bound(d+1,d+1+n,pows-c[j])-d);
      sum+=(lower_bound(d+1,d+1+n,4*pows-c[j])-d)-(lower_bound(d+1,d+1+n,3*pows-c[j])-d);
    }
    if(sum&1) ans|=1<<i;
    pows<<=1;
  }
  printf("%d\n",ans);
  return 0;
}

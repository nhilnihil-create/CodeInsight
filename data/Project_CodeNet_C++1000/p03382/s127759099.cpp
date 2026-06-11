#include<bits/stdc++.h>
using namespace std;

int a[100005];

int main() {
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++) scanf("%d",a+i);
  sort(a,a+n);
  int x = a[--n], y = a[0], z = abs(x-y*2);
  for(int i=1;i<n;i++) {
    int tmp = abs(x-a[i]*2);
    if(tmp < z) {
      z = tmp;
      y = a[i];
    }
  }
  printf("%d %d\n",x,y);
}

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <memory.h>
#include <queue>
#include <string.h>
using namespace std;

#define N 20000
#define lim 30000

int ret[N];
int gcd(int x,int y) {
  if(x==0) {
    return y;
  }
  return gcd(y%x,x);
}
void solve() {
  int n;scanf("%d ", &n);

  int pos = 0;
  if(n*2<=lim) {
    if(n==3) {
      printf("2 5 63\n");
      return;
    } else {
      ret[pos++] = 3;
      ret[pos++] = 9;
      int parity = 0;
      for(int i=2;i<=lim && pos<n;i+=2) {
        ret[pos++] = i;
        parity += i;
      }
      parity = parity%3;
      if(parity==1) {
        ret[pos-1] += 2;
      } else if(parity==2){
        ret[pos-1] +=4;
      }
    }
  } else {
    for(int i=2;i<=lim;i+=2) {
      if(i==6 && (n&1)) {
        continue;
      }
      ret[pos++] = i;
    }
    for(int i=3;i<=lim && pos<n;i+=3) {
      if(i%2==0) continue;
      ret[pos++] = i;
    }
  }
  for(int i=0;i<pos;++i) {
    printf("%d\n", ret[i]);
  }
}

int main() {
  //freopen("input.txt","r",stdin);
  solve();
  return 0;
}

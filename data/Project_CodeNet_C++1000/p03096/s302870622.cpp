#include <bits/stdc++.h>
using namespace std;

inline int read(){
  int x = 0; char c = getchar();
  while(!isdigit(c)) c = getchar();
  while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
  return x;
}

const int maxn = 2e5;
const int mod = 1e9 + 7;
int num[maxn];
int a[maxn], pre[maxn], f[maxn] = {1};

int main(){
  srand(time(0));
  memset(num, -1, sizeof(num));
  int n = read();
  for(int i = 0; i < n; i++){
    a[i] = read() - 1;
    pre[i] = num[a[i]];
    num[a[i]] = i;
  }
  for(int i = 1; i < n; i++){
    f[i] = f[i - 1];
    if(pre[i] >= 0 && pre[i] != i - 1) f[i] = (f[i] + f[pre[i]]) % mod;
  }
  printf("%d", f[n - 1]);
  return 0;
}

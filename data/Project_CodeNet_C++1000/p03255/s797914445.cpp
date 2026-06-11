#include<bits/stdc++.h>
#define MAX 200005
using namespace std;
 
int main(){
  int n;
  long long x, a[MAX], ans = 0, d;
  a[0] = 0;
  scanf("%d%lld", &n, &x);
  for(int i = 1; i <= n; i++){
    scanf("%lld", &a[i]);
    a[i] += a[i-1];
  }
  ans = a[n]*5 + (n*2-n/2)*x;
  for(int i = 1; i < n-n/2; i++){
    d = (a[n] - a[n-i])*5 + (i+n)*x;
    int j = n-i, k = 0;
    for(; j > i && d < ans; j -= i, k++)
      d += (a[j] - a[j-i])*(5+k*2);
    d += a[j]*(5+2*k);
    ans = min(ans, d);
  }
  printf("%lld\n", ans);
}
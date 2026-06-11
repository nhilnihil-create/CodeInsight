#include<bits/stdc++.h>
#define MAX 100005
using namespace std;
 
int main(){
  int n;
  long long c, x[MAX], v[MAX], u[2] = {0, 0}, w[2] = {0, 0};
  scanf("%d%lld", &n, &c);
  v[0] = x[0] = 0;
  for(int i = 1; i <= n; i++){
    scanf("%lld%lld", &x[i], &v[i]);
    v[i] += v[i-1];
  }
  v[n+1] = v[n], x[n+1] = c;
  for(int i = 1; i <= n+1; i++){
    w[0] = max(w[0], (v[n] - v[i-1]) - (c - x[i])*2 + u[0]);
    u[0] = max(u[0], (v[i] - x[i]));
    w[1] = max(w[1], (v[n] - v[i-1]) - (c - x[i]) + u[1]);
    u[1] = max(u[1], (v[i] - x[i]*2));
  }
  printf("%lld\n", max(w[0],w[1]));
}
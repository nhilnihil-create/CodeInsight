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
  for(int i = 0; i < 2; i++){
    for(int j = 1; j <= n+1; j++){
      w[i] = max(w[i], (v[n] - v[j-1]) - (c - x[j])*(2-i) + u[i]);
      u[i] = max(u[i], (v[j] - x[j]*(i+1)));
    }
  }
  printf("%lld\n", max(w[0],w[1]));
}

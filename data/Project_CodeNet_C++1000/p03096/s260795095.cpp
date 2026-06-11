#include <stdio.h>
#include <stdlib.h>
#include <vector>
#define mod 1000000007ll
typedef long long ll;
using namespace std;


int main(void) {
  ll i, j, k, n;
  scanf("%lld", &n);
  vector<ll> vec[200000];
  ll dp[n], c[n], num[200000];
  for(i = 0; i < 200000; ++i) num[i] = 0;
  for(i = 0; i < n; ++i) dp[i] = 0;
  for(i = 0; i < n; ++i) {
    scanf("%lld", &c[i]);
    --c[i];
    if(!i || c[i - 1] != c[i]) vec[c[i]].push_back(i);
  }
  dp[0] = 1;
  for(i = 0; i < n; ++i) {
    if(i) dp[i] += dp[i - 1], dp[i] %= mod;
    if(vec[c[i]][num[c[i]]] == i && num[c[i]] < vec[c[i]].size() - 1) dp[vec[c[i]][++num[c[i]]]] += dp[i], dp[vec[c[i]][num[c[i]]]] %= mod;
  }
  printf("%lld", dp[n - 1]);
  return 0;
}
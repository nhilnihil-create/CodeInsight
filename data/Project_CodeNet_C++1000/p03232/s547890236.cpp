#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

#define max(x, y) ((x)>(y)?(x):(y))
#define min(x, y) ((x)<(y)?(x):(y))

Int sum[108000];
Int n;
Int fact[108000];
Int a[108000];
Int res;

Int mod_pow(Int x, Int a, Int m = MOD){
  if(a == 0)return 1;
  Int res = mod_pow(x, a / 2, m);
  res = res * res % m;
  if(a % 2)res *= x;
  return res % m;
}

void init(){
  fact[0] = 1;
  for(int i = 1;i < 108000;i++)fact[i] = fact[i-1] * i % MOD;
}

Int inv(Int x){
  return mod_pow(x, MOD-2);
}

Int nCk(Int n, Int k){
  if(n < k)return 0;
  return fact[n] * inv(fact[k]) % MOD * inv(fact[n-k]) % MOD;
}
int main(){
  init();
  
  cin >> n;
  
  for(int i = 1;i < n;i++){
    sum[i] = nCk(n, i+1) % MOD * fact[i] %MOD * fact[n-i-1] % MOD;
    sum[i] += sum[i-1];
  }
  
  for(int i = 0;i < n;i++){
    cin >> a[i];
    res += (fact[n] + sum[i] + sum[n-i-1]) % MOD * a[i] %MOD;
    res %= MOD;
  }
  cout << res << endl;
  return 0;
}
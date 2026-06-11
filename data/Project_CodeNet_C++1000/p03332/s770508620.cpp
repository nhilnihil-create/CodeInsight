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
#define MOD 998244353
#define INF (1<<29)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

#define max(x, y) ((x)>(y)?(x):(y))
#define min(x, y) ((x)<(y)?(x):(y))

Int mod_pow(Int x, Int a, Int m = MOD){
  if(a == 0)return 1;
  Int res = mod_pow(x, a / 2, m);
  res = res * res % m;
  if(a % 2)res *= x;
  return res % m;
}

Int inv(Int x){
  return mod_pow(x, MOD-2);
}

Int fact[324000], res;

Int nCk(Int n, Int k){
  if(n < k)return 0;
  return fact[n] * inv(fact[k]) % MOD * inv(fact[n-k]) % MOD;
}

int main(){
  fact[0] = 1;
  for(Int i = 1;i < 324000;i++)fact[i] = fact[i-1] * i % MOD;
  Int n, a, b, k;
  cin >> n >> a >> b >> k;
  for(Int i = 0;i <= n;i++){
    Int red = i;
    if((k - red * a) % b)continue;
    Int blue = (k - red*a) / b;
    if(blue > n || blue < 0)continue;
    res += nCk(n, red) * nCk(n, blue) % MOD;res %= MOD;
  }
  cout << res << endl;
  return 0;
}
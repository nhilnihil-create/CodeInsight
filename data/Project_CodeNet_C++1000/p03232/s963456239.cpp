//#define _GLAIBCXX_DEBUG
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
const long long mod = (1e9) + 7;

long long mod_inv(long long x){
  long long k = mod - 2, ret = 1;
  while(k){
    if(k&1) ret *= x, ret %= mod;
    x *= x, x %= mod;
    k >>= 1;
  }
  return ret;
}

int main(){
  int N;
  cin >> N;
  vector<long long> A(N);
  for(int i = 0; i < N; ++i) cin >> A[i];
  long long f = 1;
  for(int i = 1; i <= N; ++i) f *= i, f %= mod;
  vector<long long> F(N+1,0);
  for(int i = 1; i <= N; ++i) F[i] = mod_inv(i);
  for(int i = 0; i < N; ++i) F[i+1] += F[i], F[i+1] %= mod;
  long long ans = 0;
  for(int i = 1; i <= N; ++i){
    long long t = 0;
    t += (F[i]+F[N-i+1])%mod;
    t += mod - 1, t %= mod;
    t *= f, t %= mod;
    ans += (t*A[i-1])%mod;
    ans %= mod;
    //cerr << i << " " << t << endl;
  }
  cout << ans << endl;
  return 0;
}

#include<bits/stdc++.h>

using namespace std;

const long long mod = 998244353;

long long inverse(long long a){
  long long m = mod, u = 1, v = 0;
  while(m){
    long long t = a / m;
    a -= t * m; swap(a, m);
    u -= t * v; swap(u, v);
  }
  u %= mod;
  if(u < 0) u += mod;
  return u;
}

int main(){
  int N;
  long long A, B, K;
  cin >> N >> A >> B >> K;
  long long factorial[N + 1];
  factorial[0] = 1;
  for(int i = 1; i <= N; i++){
    factorial[i] = factorial[i - 1] * i % mod;
  }
  
  long long paint = 0;
  for(int i = 0; i <= N; i++){
    int j = (K - A * i) / B;
    if(j >= 0 && j <= N && A * i + B * j == K){
      paint += factorial[N] * inverse(factorial[i]) % mod * inverse(factorial[N - i]) % mod * factorial[N] % mod * inverse(factorial[j]) % mod * inverse(factorial[N - j]) % mod;
      paint %= mod;
    }
  }
  
  cout << paint << endl;
  
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

int main(){
  string S;
  cin >> S;
  int n = S.size();

  vector<long long> p3(n + 1);
  p3[0] = 1;
  vector<long long> a(n, 0);
  vector<long long> c(n, 0);
  vector<long long> q(n, 0);
  for(int i = 0; i < n; i++){
    p3[i + 1] = p3[i] * 3 % MOD;
    if(S[i] == 'A') a[i] = 1;
    if(S[i] == 'C') c[i] = 1;
    if(S[i] == '?') q[i] = 1;
  }
  for(int i = 1; i < n; i++){
    a[i] += a[i - 1];
    c[i] += c[i - 1];
    q[i] += q[i - 1];
  }
  
  long long count = 0;
  for(int i = 1; i < n - 1; i++){
    if(S[i] == 'B' || S[i] == '?'){
      int bq = S[i] == '?' ? 1 : 0;
      count += a[i - 1] * (c[n - 1] - c[i]) % MOD * p3[q[n - 1] - bq] % MOD;
      count %= MOD;
      count += q[i - 1] * (c[n - 1] - c[i]) % MOD * p3[q[n - 1] - 1 - bq] % MOD;
      count %= MOD;
      count += a[i - 1] * (q[n - 1] - q[i]) % MOD * p3[q[n - 1] - 1 - bq] % MOD;
      count %= MOD;
      count += q[i - 1] * (q[n - 1] - q[i]) % MOD * p3[q[n - 1] - 2 - bq] % MOD;
      count %= MOD;
    }
  }
  
  cout << count << endl;
  
  return 0;
}
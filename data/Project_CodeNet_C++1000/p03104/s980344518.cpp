#include <bits/stdc++.h>
using namespace std;

long long f(long long n){
  if(n == 0) return 0;
  long long res;
  long long tmp = (n + 1) / 2;
  res = tmp % 2;
  if(n % 2 == 0) res ^= n;
  return res;
}

int main(){
  long long A, B; cin >> A >> B;
  long long ans;
  ans = f(A-1) ^ f(B);
  cout << ans << endl;
}
    
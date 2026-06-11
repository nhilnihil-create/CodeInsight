#include <bits/stdc++.h>
using namespace std;

long long gcd(long long n, long long m){
  if(n % m == 0) return m;
  n = n % m;
  return gcd(m, n);
}

long long lcm(long long n, long long m){
  return m * n / gcd(n, m);
}

int main() {
  long long n, m;
  string s, t;
  cin >> n >> m >> s >> t;
  
  bool ok = true;
  long long mul = n * m;
  for(long long i = 0; i < n; i++){
    if(i * m % n) continue;
    long long num = i * m / n;
    if(num >= m) break;
    char sc = s.at(i), tc = t.at(num);
    if(sc != tc) ok = false;
  }
  
  if(ok) cout << lcm(n, m) << endl;
  else cout << -1 << endl;
}
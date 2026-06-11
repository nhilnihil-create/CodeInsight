#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define DD long double

#define M 1000000007
#define INF 1e18

void setIO(string s = "") { 
  cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
  if (s.size()) s += ".in", freopen(s.c_str(), "r", stdin);
}

LL fib(int n) 
{ 
    
  LL f[n + 2];  
  LL i; 

  // 0th and 1st number of the  
  // series are 0 and 1 
  f[0] = 2; 
  f[1] = 1; 

  for(i = 2; i <= n; i++) 
  { 
    f[i] = f[i - 1] + f[i - 2]; 
  } 
  return f[n]; 
} 

int tt = 1;
void solve() {
  int n;
  cin >> n;
  cout << fib(n) << endl;
  //cout << fib(86) << endl;
}

int main() {
  setIO();
  while (tt--) {
    solve();
  }
  return 0;
}
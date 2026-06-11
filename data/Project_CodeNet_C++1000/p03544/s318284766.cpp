#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
ll memo[87] = {0};

ll lucas(ll n) {
  if (n == 0) return 2;
  if (n == 1) return 1;
  if (memo[n] > 0) return memo[n];
  memo[n] = lucas(n - 1) + lucas(n - 2);
  return memo[n];
}

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  ll n; cin >> n;
  cout << lucas(n) << "\n";
}

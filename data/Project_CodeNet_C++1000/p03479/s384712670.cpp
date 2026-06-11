#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

  ll A, B;
  cin >> A >> B;
  ll ans = 1;
  ll x = A;
  while(x<=B) {
    x *= 2;
    ans++;
  }
  ans--;
  cout << ans << endl; 
}
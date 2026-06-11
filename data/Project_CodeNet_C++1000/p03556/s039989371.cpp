#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  ll n;
  cin >> n;

  ll low = 1, high = n;

  while (low < high) {
    ll mid = low + (high - low + 1) / 2;
    ll square = mid * mid;

    if (square <= n) low = mid;
    else high = mid - 1;
  }

  cout << (low * low) << "\n";
}

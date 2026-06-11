#include <iostream>
using namespace std;

typedef unsigned long long ll;

int main() {
  ll n;
  cin >> n;
  ll sum = 0;
  ll tmp = 0;
  bool same = true;
  ll rem = 1001001001;
  for (int i = 0; i < n; ++i) {
    ll a, b;
    cin >> a >> b;
    sum += b;
    if (a < b) { same = false; } 
    if (a > b) {
      rem = min(rem, b);
    }
  }
  if (same) {
    cout << 0 << endl;
  }
  else {
    cout << sum - rem << endl;
  }
}


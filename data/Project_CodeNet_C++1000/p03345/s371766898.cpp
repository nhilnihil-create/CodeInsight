#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define rep(i,n) for(int i = 0; i < n; i++)

int main() {
  ll a,b,c,k;
  cin >> a >> b >> c >> k;
  if (a-b > 1000000000000000000) {
    cout << "Unfair" << endl;
  }
  else if (k%2 == 1) {
    cout << b - a << endl;
  }
  else {
    cout << a - b << endl;
  }
  return 0;
}
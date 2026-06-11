#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  double N;
  cin >> N;
  ll ans = 0;
  for(int i = 1; i <= sqrt(N); i++) {
    if(i * i <= N) ans = i * i; 
  }

  cout << ans;
  return 0;
}


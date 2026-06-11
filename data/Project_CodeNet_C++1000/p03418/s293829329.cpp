#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  long long int total = 0;
  for(int i=k+1;i<=n;i++) {
    total += (n / i) * (i - k);
    if(n % i != 0 && n % i >= k) {
      if(k != 0) total += (n % i) - k + 1;
      else total += (n % i) - k;
    }
  }

  cout << total << endl;
}
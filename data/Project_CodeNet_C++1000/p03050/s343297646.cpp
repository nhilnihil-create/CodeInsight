#include<bits/stdc++.h>
using namespace std;
int main() {
  long long n; cin >> n;
  long long res = 0;
  for(long long i = 1; i * i < n; i++) {
    if(n % i == 0 && n % (n/i - 1) != 0) {
      res += n/i - 1;
    }
  }
  cout << res << endl;
}

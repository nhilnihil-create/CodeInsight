#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const long long inf = 1LL<<60;

bool is_prime(int n) {
  if(n <= 1) return false;
  else if(n == 2) return true;
  else if(n % 2 == 0) return false;
  else {
    for(int i = 3; i*i <= n; i+=2) {
      if(n % i == 0) return false;
    }
    return true;
  }
}

int main() {
  int q; cin >> q;
  vector<int> s(100010, 0);
  for(int i = 1; i < 100010; i++) {
    if(is_prime(i) && is_prime((i+1)/2)) s[i] = s[i-1] + 1;
    else s[i] = s[i-1];
  }
  for(int i = 0; i < q; i++) {
    int l, r; cin >> l >> r; l--;
    cout << s[r] - s[l] << endl;
  }
  return 0;
}

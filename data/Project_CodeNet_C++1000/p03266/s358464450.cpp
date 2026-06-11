#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k; 
  cin >> n >> k;
  long long res, num;
  if (k%2 == 0) {
    num = n/(k/2);
    res = (num/2)*(num/2)*(num/2);
    res += (num-num/2)*(num-num/2)*(num-num/2);
  } else {
    num = n/k;
    res = num*num*num;
  }
  cout << res << endl;

  return 0;
}


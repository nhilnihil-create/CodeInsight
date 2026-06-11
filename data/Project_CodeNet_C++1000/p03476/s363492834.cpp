#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const long long int INF = 1LL<<60;
const long long int mod = 1e9 + 7;

bool is_prime(int n) {
  if(n < 2) return false;
  else if(n == 2) return true;
  else if(n%2 == 0) return false;

  double sqrt_n = sqrt(n);
  for(int i=3; i<=sqrt_n; i+=2) {
    if(n%i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int Q;
  cin >> Q;
  vector<int> l(Q);
  vector<int> r(Q);
  int max_r = 0;
  for(int i=0; i<Q; i++) {
    cin >> l.at(i) >> r.at(i);
    max_r = max(max_r, r[i]);
  }

  // prime[k]: the number of x when li=1 and ri = k
  vector<int> prime(max_r+1, 0);
  prime[0] = 0;
  for(int i=1; i<=max_r; i++) {
    if(i%2 == 1) {
      if (is_prime(i)) {
        int j = (i + 1) / 2;
        if(is_prime(j)) {
          prime[i] = prime[i-1] + 1;
        } else {
          prime[i] = prime[i-1];
        }
      } else {
        prime[i] = prime[i-1];
      }
    } else {
      prime[i] = prime[i-1];
    }
  }

  for(int i=0; i<Q; i++) {
    int res = prime[r[i]] - prime[l[i]-1];
    cout << res << endl;
  }

  return 0;
}
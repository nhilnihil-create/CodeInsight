#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
  for (int i=2; i<=sqrt(n); i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  int n;
  cin>>n;
  vector<int> v;
  for (int i=3; i<=55555; i+=2) {
    if (is_prime(i) && i % 5 == 1) {
      v.push_back(i);
      if (v.size() > n) {
        break;
      }
    }
  }
  for (int i=0; i<n; i++) {
    cout<<v[i];
    if (i != n - 1) {
      cout<<" ";
    }
  }
  cout<<endl;
}
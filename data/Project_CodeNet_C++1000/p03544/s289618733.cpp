#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> v(n+1);
  v[0] = 2;
  v[1] = 1;
  for(int i = 2; i < n+1; i++) {
    v[i] = v[i-1]+v[i-2];
  }
  cout << v[n];
}
#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<long long int> vec(100);
  vec[0] = 2;
  vec[1] = 1;
  for(long long int i = 2; i < 100; i++) {
    vec[i] = vec[i - 2] + vec[i - 1];
  }
  cout << vec[N] << endl;
}
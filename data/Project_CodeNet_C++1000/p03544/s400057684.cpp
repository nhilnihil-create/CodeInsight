#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int64_t> a(90);
  a.at(0) = 2LL;
  a.at(1) = 1LL;
  
  for (int i = 0; i < 88; i++) a.at(i + 2) = a.at(i + 1) + a.at(i);
  
  cout << a.at(N) << endl;
}

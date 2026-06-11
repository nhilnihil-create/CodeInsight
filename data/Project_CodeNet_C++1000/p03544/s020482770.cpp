#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<int64_t> l(3);
  l.at(0) = 2;
  l.at(1) = 1;
  for (int i = 2; i <= n; i++){
    l.at(i%3) = l.at((i-1)%3) + l.at((i-2)%3);
  }
  
  cout << l.at(n%3) << endl;
}
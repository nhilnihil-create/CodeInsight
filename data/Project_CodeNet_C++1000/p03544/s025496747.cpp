#include <bits/stdc++.h>
using namespace std;

int main() {
  int N = 0;
  cin >> N;

  vector<uint64_t> L(N+1);
  
  L.at(0) = 2;
  L.at(1) = 1;

  for (int i = 2; i < L.size(); i++) {
    L.at(i) = L.at(i-1) + L.at(i-2);
  }
  
  cout << L.at(L.size()-1) << endl;
}

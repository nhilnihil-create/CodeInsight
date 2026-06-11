#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<uint64_t> A;
  A.push_back(2LL);
  A.push_back(1LL);
  
  for (int i = 2; i <= N ; i++) {
    A.push_back(A.at(i - 2) + A.at(i - 1));
  }
  cout << A.at(N) << endl;
}
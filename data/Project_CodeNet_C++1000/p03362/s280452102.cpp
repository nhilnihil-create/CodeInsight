#include <bits/stdc++.h>
using namespace std;
 
vector<int> list_of_possible_primes() {
  // 1381 is the 55th number which satisfies the requirements of this problem.
  const int SEIVE_SIZE = 1381; // 55555;
  vector<bool> seive(SEIVE_SIZE + 1, true);
  seive[0] = false;
  seive[1] = false;
  for (int i = 2; i * i <= SEIVE_SIZE; ++i) {
    for (int j = i + i; j <= SEIVE_SIZE; j += i) {
      seive[j] = false;
    }
  }
  vector<int> list;
  for (int i = 0; i <= SEIVE_SIZE; ++i) {
    if (seive[i] && i % 5 == 1) {
      list.push_back(i);
    }
  }
  return list;
}
 
int main() {
  int n;
  cin >> n;
 
  vector<int> ps = list_of_possible_primes();
 
  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      cout << " ";
    }
    cout << ps[i];
  }
  cout << endl;
}
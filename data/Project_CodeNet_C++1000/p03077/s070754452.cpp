#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int64_t N;
  cin >> N;
  int64_t memo = 10000000000000000;
  for (int i = 0; i < 5; i++) {
    int64_t memo2;
    cin >> memo2;
    memo = min(memo2, memo);
  }
  cout << 5 + (N - 1)/ memo << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  bitset<100000> bit(S);
  int count1 = bit.count();
  int min01 = min(N - count1, count1);
  
  cout << 2 * min01 << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int64_t N; cin >> N; N++;
  
  string S = to_string(N);
  
  int headDigit = stoi(S.substr(0, 1)) - 1;
  
  int sum = headDigit + 9 * (S.size() - 1);
  
  cout << sum << endl;
  
}
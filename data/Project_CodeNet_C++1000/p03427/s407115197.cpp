#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  string N;
  cin >> N;
  int digit = N.size();
  int head = N[0] - '0';
  bool can = true;
  for (int i = 1; i < digit; i++) {
    if (N[i] != '9') {
      can = false;
    }
  }
  if (!can) head--;
  cout << ((digit - 1) * 9) + head << endl;
  return 0;
}
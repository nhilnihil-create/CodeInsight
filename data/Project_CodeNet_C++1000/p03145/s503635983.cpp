#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int A[3];
  cin >> A[0] >> A[1] >> A[2];
  sort(A,A+3);
  cout << (A[0] * A[1]) / 2 << endl;
  return 0;
}
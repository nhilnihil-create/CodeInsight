#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N,A,B;
  cin >> N >> A >> B;
  cout << min(B,A*N) << endl;
  return 0;
}
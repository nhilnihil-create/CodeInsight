#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int a,b;
  cin >> a >> b;
  if ((a * b) % 2 == 0) {
    cout << "Even" << endl;
  } else {
    cout << "Odd" << endl;
  }
  return 0;
}
#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int main() {
  int a, b;
  cin >> a >> b;
  cout << (a & b  & 1 ? "Odd" : "Even") << endl;

  return 0;
}
#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a, b, c;
  cin >> a >> b >> c;
  if(a == b && b == c)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
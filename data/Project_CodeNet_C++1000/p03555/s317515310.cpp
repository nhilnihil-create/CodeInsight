#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  string a, b;
  cin >> a >> b;
  reverse(a.begin(), a.end());
  if(a == b) cout << "YES" << endl;
  else cout << "NO" << endl;
}
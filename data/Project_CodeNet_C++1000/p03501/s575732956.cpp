#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
  int n,a,b;
  cin >> n >> a >>b;
  if(n*a <= b) cout << n*a << endl;
  else cout << b << endl;
}
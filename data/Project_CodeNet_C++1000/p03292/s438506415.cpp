#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll MOD=1000000007;

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  cout << max(abs(c-b),max(abs(a-b),abs(c-a)));
}
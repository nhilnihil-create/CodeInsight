#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int a, b;

int main(){
  cin >> a >> b;
  if (a == b) cout << a + b << endl;
  else cout << 2 * max(a, b) - 1 << endl;
}

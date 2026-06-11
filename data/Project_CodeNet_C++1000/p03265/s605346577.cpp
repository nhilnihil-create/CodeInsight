#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int A, B, a, b;
  cin >> A >> B >> a >> b;
  cout << a-(b-B) << endl;
  cout << b+(a-A) << endl;
  cout << a-(b-B)-(a-A) << endl;
  cout << b+(a-A)-(b-B) << endl;
}

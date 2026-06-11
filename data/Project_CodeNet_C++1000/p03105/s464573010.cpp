#include <bits/stdc++.h>

#define REP(i, x) for (int i = 0; i < (int)(x); i++)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int A, B, C;
  cin >> A >> B >> C;
  cout << min(C, B / A) << endl;

  return 0;
}

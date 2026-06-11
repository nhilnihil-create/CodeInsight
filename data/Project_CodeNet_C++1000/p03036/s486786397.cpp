#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i = 0; i < (ll)n; i++)
#define all(x) (x).begin(), (x).end()
#define unique(x) x.erase(unique(x.begin(), x.end()), x.end());
// map<int,int> mp;

int mo(int r, int d, int x) { return x * r - d; }
int main() {
  int r, d, xi;
  cin >> r >> d >> xi;
  for (int i = 0; i < 10; i++) {
    int tmp = mo(r, d, xi);
    cout << tmp << endl;
    xi = tmp;
    ;
  }
}
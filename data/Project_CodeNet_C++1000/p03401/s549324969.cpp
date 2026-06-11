#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int n;
  cin >> n;
  vector<int> b(n + 1);
  int a = 0, na;
  rep(i, n) {
    cin >> na;
    b[i] = na - a;
    a = na;
  }
  b[n] = 0 - a;
  int sum = 0;
  rep(i, n + 1) sum += abs(b[i]);
  vector<int> c(n, sum);
  rep(i, n + 1) if(b[i + 1] * b[i] <= 0) c[i] -=
    2 * min(abs(b[i + 1]), abs(b[i]));
  rep(i, n) cout << c[i] << endl;

  return 0;
}
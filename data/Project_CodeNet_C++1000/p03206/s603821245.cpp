#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using ll = long long;
using P = pair<int, int>;
#define debug(var) cout << "[" << #var << "] " << var << endl
const ll mod = 1000000007;
 
int main() {
  int d;
  cin >> d;
  string a[4] = {"Christmas", "Christmas Eve", "Christmas Eve Eve", "Christmas Eve Eve Eve"};
  cout << a[25-d] << endl;
  return 0;
}
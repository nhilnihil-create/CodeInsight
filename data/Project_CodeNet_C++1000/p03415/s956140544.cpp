#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

int main() {
  
  vector<string> c(3);
  rep(i,3) cin >> c[i];

  cout << c[0][0] << c[1][1] << c[2][2] << endl;

  return 0;
}
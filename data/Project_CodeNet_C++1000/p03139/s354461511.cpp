#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  cout << min(a, b) << " " << max(a + b - n, 0) << endl;
  return 0;
}
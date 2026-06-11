#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int n, k;
  cin >> n >> k;
  ll ans;
  int a = n / k;
  ans = (ll)a * a * a;
  if(k % 2 == 0) {
    int b = (n * 2) / k - a;
    ans += (ll)b * b * b;
  }
  cout << ans << endl;
  return 0;
}
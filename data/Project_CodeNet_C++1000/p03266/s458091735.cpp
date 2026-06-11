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
  ll n, k;
  cin >> n >> k;
  ll a = n / k;
  ll b = (n + k / 2LL) / k;
  if(k % 2 == 1) {
    cout << a * a * a << endl;
  } else {
    cout << a * a * a + b * b * b << endl;
  }
  return 0;
}
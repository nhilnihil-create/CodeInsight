#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;
using ll = long long int;

int main() {
  ll man = 0;
  ll go = 0;
  ll sen = 0;

  ll N, Y;
  cin >> N >> Y;
  Y /= 1000;

  bool ok = false;
  for (ll i = 0; i <= N; i++)
  {
    for (ll j = 0; j <= N; j++)
    {
      ll k = N - i - j;
      if (k < 0) {
        continue;
      }
      ll sum = i * 10 + 5 * j + k;
      if (sum == Y && (i + j + k) == N) {
        ok = true;
        man = i;
        go = j;
        sen = k;
        break;
      }
    }
  }

  if (ok) {
    cout << man << " " << go << " " << sen << endl;
  } else {
    cout << "-1 -1 -1" << endl;
  }
  
}
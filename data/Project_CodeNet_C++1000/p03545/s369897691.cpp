#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;
using ll = long long int;

int main() {
  string S;
  cin >> S;

  string ans;
  for (ll i = 0; i < (1 << 4); i++)
  {
    ll sum = S[0] - '0';
    for (ll j = 1; j < 4; j++)
    {
      if (bitset<4>(i)[j]) {
        sum += S[j] - '0';
      } else {
        sum -= S[j] - '0';
      }
    }

    if (sum == 7) {
      for (ll j = 1; j < 4; j++)
      {
        if (bitset<4>(i)[j]) {
          ans += '+';
        } else {
          ans += '-';
        }
      }
      ans += '=';
      break;
    }
  }
  S += '7';

  for (ll i = 0; i < 4; i++)
  {
    cout << S[i] << ans[i];    
  }
  cout << 7 << endl;
}
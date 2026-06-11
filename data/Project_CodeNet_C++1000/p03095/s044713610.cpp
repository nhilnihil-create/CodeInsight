#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

ll freq[26];
int main() {
  ll n;
  string letters;
  cin >> n >> letters;

  memset (freq, 0, sizeof (freq));

  for (ll i=0; i < n; i++){
    int f = letters[i] - 'a';
    freq[f]++;
  }

  ll ans = 1;
  for (int i=0; i < 26; i++){
    ll d = freq[i]+ 1;
    ans = ans*d;
    ans = ans%1000000007;
  }

  ans = ans - 1;
  cout << ans << endl;
}
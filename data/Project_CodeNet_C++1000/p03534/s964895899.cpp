#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

string S;

int main(void) {
  cin >> S;

  ll a = 0, b = 0, c = 0;
  REP(i, 0, S.length()) {
    if(S[i] == 'a') a++;
    if(S[i] == 'b') b++;
    if(S[i] == 'c') c++;
  }

  if(abs(a - b) <= 1 && abs(b - c) <= 1 && abs(c - a) <= 1) cout << "YES" << endl;
  else cout << "NO" << endl;
}

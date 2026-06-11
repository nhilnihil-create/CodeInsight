#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll INF = (ll)5e15;

int main() {
  string s;
  ll k;
  cin >> s >> k;
  ll n = s.length();
  if(s[0] == '1') {
    ll cnt = 0;
    ll i = 0;
    while(s[i] == '1' && i < n) {
      cnt++;
      i++;
    }
    if (cnt < k) cout << s[i] << endl;
    else cout << s[i-1] << endl;
  } else cout << s[0] << endl;
  return 0;
}
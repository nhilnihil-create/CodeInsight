#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  int n;
  cin >> n;
  map<char, ll> s;
  rep(i,n) {
    string t; cin >> t;
    char c = t[0];
    s[c]++;
  }
  ll ans = 0;
  char v[5] = {'M','A','R','C','H'};

  rep(i,3) {
    for (int j = i+1; j < 4; j++)
    {
      for (int k = j+1; k < 5; k++)
      {
        ans += s[v[i]] * s[v[j]] * s[v[k]];
      }
      
    }
    
  }
  cout  << ans << endl;
  return 0;
}
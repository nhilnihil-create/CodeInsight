#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;
using ll = long long;

char chars[10][3] = {
  {'M', 'A', 'R'},
  {'M', 'A', 'C'},
  {'M', 'A', 'H'},
  {'M', 'R', 'C'},
  {'M', 'R', 'H'},
  {'M', 'C', 'H'},
  {'A', 'R', 'C'},
  {'A', 'R', 'H'},
  {'A', 'R', 'H'},
  {'R', 'C', 'H'},
};

int main() {
  int N;
  cin >> N;

  vector<ll> a(5, 0);
  rep(i,0,N-1) {
    string s;
    cin >> s;
    switch (s[0])
    {
    case 'M':
      a[0]++;
      break;    
    case 'A':
      a[1]++;
      break;    
    case 'R':
      a[2]++;
      break;    
    case 'C':
      a[3]++;
      break;    
    case 'H':
      a[4]++;
      break;
    default:
      break; 
    }
  }

  ll ans = 0;
  for (int i = 0; i < 3; ++i)
    for (int j = i + 1; j < 4; ++j)
      for (int k = j + 1; k < 5; ++k)
        ans = ans + a[i] * a[j] * a[k];

  cout << ans << endl;
  return 0;
}

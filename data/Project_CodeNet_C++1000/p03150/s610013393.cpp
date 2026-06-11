#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;

const string K = "keyence";

int main()
{
  string s; cin >> s;
  int n = s.size();

  for (int i=0; i<n; i++) {
    for (int j=i; j<=n; j++) {
      if (K == s.substr(0, i)+s.substr(j)) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;

  return 0;
}

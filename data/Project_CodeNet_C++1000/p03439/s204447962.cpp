#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;

int main()
{
  int n; cin>>n;
  cout << 0 << endl;

  string t; cin >> t;
  if (t == "Vacant") return 0;

  int l = 1;
  int r = n;
  while (true) {
    int m = (l+r)/2;
    cout << m << endl;

    string s; cin>>s;
    if (s=="Vacant") {
      return 0;
    }

    if (m%2) {
      if (t==s) r = m;
      else l = m;
    } else {
      if (t==s) l = m;
      else r = m;
    }
  }

  return 0;
}

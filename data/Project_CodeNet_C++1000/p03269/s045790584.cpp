#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int l;
  cin >> l;
  l--;

  int n = 19;
  vector < tuple < int, int, int > > ans;
  while (l > 0) {
    tuple < int, int, int > tp (n, n + 1, 0);
    ans.push_back (tp);
    if (l % 2 == 0) {
      ans.push_back (make_tuple (1, n + 1, l));
      l--;
    }
    get < 2 > (tp) = (l + 1) / 2;
    ans.push_back (tp);
    l = (l - 1 ) / 2;
    n--;
  }

  cout << 20 - n << " " << ans.size() << '\n';
  for (auto i : ans) {
    cout << max (1, get < 0 > (i) - n) << " " << get < 1 > (i) - n << " " << get < 2 > (i) << '\n';
  }
}

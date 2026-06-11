#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n, ans=0;

  cin >> n;
  vector<string> s(n);
  rep(i, n)
  {
    cin >> s.at(i);
  }

  int m;
  cin >> m;
  vector<string> t(m);
  rep(i, m)
  {
    cin >> t.at(i);
  }

  int tmp=0;
  rep(i, n)
  {
    tmp = count(s.begin(), s.end(), s.at(i));

    rep(j, m)
    {
      if(s.at(i) == t.at(j))
        tmp--;
    }

    ans = max(ans, tmp);
    
  }


  cout << ans << endl;

}

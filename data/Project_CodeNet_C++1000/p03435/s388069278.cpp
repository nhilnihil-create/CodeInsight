#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) v.begin(), v.end()
#define chmax(x,y) (x = max(x,y))
#define chmin(x,y) (x = min(x,y))

using ll = long long;
using PAIR = pair<int, int>;
using PAIRLL = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vll = vector<ll>;
using vvll = vector<vll>;

int main()
{
  vvi c(3, vi(3));
  rep(i,3)
  {
    rep(j,3)
    {
      cin >> c[i][j];
    }
  }

  int d1 = c[0][1] - c[0][0], d2 = c[0][1] - c[0][2];

  bool check = true;
  for (int i = 1; i < 3; i++)
  {
    if(c[i][1]-c[i][0]!=d1||c[i][1]-c[i][2]!=d2)
      check = false;
  }

  if(check)
    cout << "Yes" << endl;
    else
      cout << "No" << endl;

}

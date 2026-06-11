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
  ll N,alice=0,bob=0;
  cin >> N;
  vll a(N);
  rep(i,N)
  {
    cin >> a[i];
  }
  sort(all(a));
  reverse(all(a));

  rep(i,N)
  {
    if(i%2)
      bob += a[i];
      else
        alice += a[i];
  }
  cout << alice - bob << endl;
}

#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define mt make_tuple

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;

const int inf = 1e9;
const ll linf = 1LL<<60;
const ll mod = 1e9 + 7;
const double eps = 1e-9;

/*
*/

ll f(ll x)
{
  ll res = 0;
  while(x > 0){
    res += x%10;
    x /= 10;
  }
  return res;
}

double g(ll x)
{
  return (double)x/f(x);
}

int main()
{
  vl ans;

  ll t = 1;
  rep(i, 15){
    repi(j, 1, 150){
      ans.pb(t*(j+1)-1);
    }
    t *= 10;
  }

  sort(all(ans));
  ans.erase(unique(all(ans)), ans.end());

  rep(i, ans.size()){
    repi(j, i+1, ans.size()){
      if(g(ans[i]) > g(ans[j])){
        ans.erase(ans.begin()+i--);
        break;
      }
    }
  }

  int k;
  cin >> k;
  rep(i, k){
    cout << ans[i] << endl;
  }

  return 0;
}

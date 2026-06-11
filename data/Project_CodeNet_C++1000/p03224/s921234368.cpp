#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
        #define eprintf(...) 42
#endif

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(x) (x).begin(),(x).end()
#define foreach(u,v) for(auto (u) : (v))
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

int main()
{
  int n;
  cin >> n;

  ll k;
  bool exist = false;
  for(k = 1; k <= n; k++){
    if(k*(k+1)/2 == n){
      exist = true;
      break;
    }
  }

  if(!exist) cout << "No" << endl;
  else{
    cout << "Yes" << endl;
    cout << k+1 << endl;

    vector<vl> res(k+1, vl());
    ll sum = 1;
    for(int i = k; i >= 1; i--){
      rep(j, i){
        res[k-i].pb(sum+j);
        res[k-i+j+1].pb(sum+j);
      }
      sum += i;
    }

    rep(i, k+1){
      cout << res[i].size();
      for(ll j : res[i]) cout << " " << j;
      cout << endl;
    }
  }

  return 0;
}

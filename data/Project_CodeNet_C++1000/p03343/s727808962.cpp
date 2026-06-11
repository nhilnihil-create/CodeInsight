#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define mt make_tuple

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int inf = 1LL<<60;
const int mod = 1e9 + 7;
const double eps = 1e-9;

/*{
}*/


signed main()
{
  int n, k, q;
  cin >> n >> k >> q;

  vi a(n);
  rep(i, n){
    cin >> a[i];
  }

  int ans = inf;
  rep(i, n){
    vi v, w;
    rep(j, n){
      if(a[j] < a[i]){
        if(v.size() >= k){
          sort(all(v));
          rep(l, v.size()-k+1) w.pb(v[l]);
        }
        v.clear();
      }else{
        v.pb(a[j]);
      }
    }

    if(v.size() >= k){
      sort(all(v));
      rep(l, v.size()-k+1) w.pb(v[l]);
    }

    if(w.size() >= q){
      sort(all(w));
      ans = min(ans, w[q-1]-w[0]);
    }
  }

  cout << ans << endl;

  return 0;
}

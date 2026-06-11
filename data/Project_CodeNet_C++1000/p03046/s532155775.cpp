#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()

using namespace std;

typedef long long ll;
typedef long double ld;

using P = pair<int, int>;

static const long long MOD = 1000000007;
static const long long LINF = (ll)(1e18+99);
static const int INF = 1e9+99;

bool used[1000000];


int main(void) {
    int m, k;
    cin >> m >> k;
    
    if (k>=(1<<m) || (m==1 && k==1) ){
      puts("-1");
      return 0;
    }
    
    vector<P> v;
    
    rep(i, 0, (1<<m)) {
      int j = i^k;
      if (used[j]) continue;
      v.pb(mp(i, j));
      used[i] = used[j] = true;
    }
    
    int n = sz(v);
    if (k!=0) rep(i, 0, n) {
      v.pb(mp(v[i].second, v[i].first));
    }
    
    rep(i, 0, sz(v)) {
      if (i>0) printf(" ");
      printf("%d %d", v[i].first, v[i].second);
    }
    cout << "\n";
    return 0;
}



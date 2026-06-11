#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second
const int INF = 987654321;
const ll MOD = 1000000007;

int main(void) {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
  //freopen("in.txt", "r", stdin);
  int n;
  cin >> n;
  bool isOdd = false;
  if(n%2) {
    isOdd = true;
    n--;
  }
  vector<pair<int, int>> ret;
  vector<pair<int, int>> v;
  rep(i,1,n/2 + 1) {
    v.pb(mp(i, n - i + 1));
  }
  rep(i,0,sz(v)) {
    rep(j,i+1,sz(v)) {
      ret.pb(mp(v[i].F, v[j].F));
      ret.pb(mp(v[i].F, v[j].S));
      ret.pb(mp(v[i].S, v[j].F));
      ret.pb(mp(v[i].S, v[j].S));
    }
  }
  if(isOdd) {
    rep(i,1,n+1) {
      ret.pb(mp(i, n+1));
    }
  }
  cout << sz(ret) << endl;
  rep(i,0,sz(ret)) {
    cout << ret[i].F << ' ' << ret[i].S << endl;
  }

  return 0;
}
#include <bits/stdc++.h>
using namespace std;

#if DEBUG && !ONLINE_JUDGE
  #include "header.h"
#else
  #define debug(args...)
#endif

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long lli;
typedef long double ld;

#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) (int)(x).size()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define rep(i,a,b) for(auto i=(a);i<b;i++)

#define INF (int)1e9
#define EPS 1e-9
#define MOD 1000000007
void preprocess(void) {
  return;
}
bitset<4000001> p;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(20);
  preprocess();
  int n; cin>>n;
  vi a(n);
  rep(i,0,n) cin>>a[i];
  int sum = 0;
  rep(i,0,n) sum += a[i];
  sum = (sum + 1)/2;
  debug(sum);
  p.set(a[0]);
  p.set(0);
  rep(i,1,n) {
    p = p | (p<<(a[i]));
  }
  int ans = 0;
  rep(i,sum,4000001) {
    if(p[i] == 1) {
      //debug(i);
      ans = i;
      break;
    }
  }
  debug(ans);
  cout<<ans<<endl;

}


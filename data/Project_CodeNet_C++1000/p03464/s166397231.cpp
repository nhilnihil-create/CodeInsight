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
vi a;
int n;
lli f(lli x) {
  rep(i,0,n) {
    x = x - (x % a[i]);
  }
  return x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(20);
  preprocess();
  int k; cin>>k;
  n = k;
  a.resize(n);
  rep(i,0,k) cin>>a[i];
  lli l = 0, r = (long long int)1e18;
  while((r-l)>1) {
    lli mid = (l + r)/2;
    if(f(mid)>=2) {
      r = mid;
    }
    else l = mid;
  }
  if(f(r) != 2) {
    cout<<-1<<endl;
    return 0;
  }
  cout<<r<<" ";
  l = 0; r = (long long int)1e18;
  while((r-l)>1) {
    lli mid = (l + r) / 2;
    if(f(mid) > 2) {
      r = mid;
    }
    else l = mid;
  }
  cout<<l<<endl;
}


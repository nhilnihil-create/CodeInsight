#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<ll> a(n),b(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  ll ans = 0;
  // ll pa,pb;
  // pa = pb = 0;
  for(int i = 28; i>=0;i--){
    sort(b.begin(),b.end());
    int c1 = 0;
    // cout << "i " << i << endl;
    rep(j,n){
      ll lb = (1<<i) - a[j];
      ll ub = (1<<(i+1)) - 1 - a[j];
      // cout << ub << " " << lb << endl;
      // cout << (upper_bound(b.begin(),b.end(),ub) - lower_bound(b.begin(),b.end(),lb)) << endl;
      c1 += (upper_bound(b.begin(),b.end(),ub) - lower_bound(b.begin(),b.end(),lb));
      c1 = c1 & 1;
      lb += 1<<(i+1);
      ub += 1<<(i+1);
      c1 += (upper_bound(b.begin(),b.end(),ub) - lower_bound(b.begin(),b.end(),lb));
      c1 = c1 & 1;
    }
    if(c1) {
      ans = ans | (1<<i);
    }
    rep(j,n){
      a[j] = a[j] & ((1<<i) -1);
      b[j] = b[j] & ((1<<i) -1);
    }
  }
  cout << ans << endl;

  return 0;
    

}

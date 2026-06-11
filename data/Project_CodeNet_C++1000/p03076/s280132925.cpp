#include <bits/stdc++.h>
#define rep(i, e, n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const ll inf=1000000000007;

int main() {
  vector<int> a(5);
  rep(i,0,5) cin >> a[i];
  int tend= 10;
  rep(i,0,5) {
    int d = a[i]%10;
    if(d==0) d=10;
    tend= min(tend, d);
  }
//  cout << tend << endl;
  int ans=0;
  rep(i,0,5) ans= ans +(int)((a[i]-0.5)/10)*10 +10;
  ans-=10;
  ans+=tend;
  cout << ans << endl;
  return 0;
}
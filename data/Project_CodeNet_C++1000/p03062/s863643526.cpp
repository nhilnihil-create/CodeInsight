#include <bits/stdc++.h>
#define rep(i, e, n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const ll inf=1000000000007;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,0,n) cin >> a[i];
  int cnt=0;
  rep(i,0,n){
    if(a[i]<0) cnt++;
  }
  vector<ll> ab(n);
  rep(i,0,n) ab[i]=abs(a[i]);
  ll t=0;
  rep(i,0,n) t+=ab[i]; 

  if(cnt%2==0){
    cout << t << endl;
    return 0;
  }
  sort(ab.begin(), ab.end());
//  cout << cnt <<' ' << ab[0] << ' ' << t << endl;
  cout << t - ab[0]*2 << endl;
  return 0;
}
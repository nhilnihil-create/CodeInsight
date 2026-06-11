#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int main(){
  
  ll n;
  cin >> n;
  vector<ll> a(n),b(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  ll sumA = accumulate(all(a),0LL);
  ll sumB = accumulate(all(b),0LL);
  if(sumA < sumB){
    cout << -1 << endl;
    return 0;
  }
  vector<ll> c(0);
  ll d = 0;
  ll ans1 = 0;
  rep(i,n){
    if(a[i]-b[i] >= 0){
      c.push_back(a[i]-b[i]);
    }else{
      d += b[i]-a[i];
      ans1 ++;
    }
  }
  if(ans1 == 0){
    cout << 0 << endl;
    return 0;
  }
  sort(all(c));
  reverse(all(c));
  ll ans2 = 0;
  for(ll p : c){
    ans2 ++;
    d -= p;
    if(d < 0) break;
  }
  cout << ans1 + ans2 << endl;
}
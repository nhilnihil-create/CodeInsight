#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fr(i,n) for(ll i=0;i<(n);++i)
#define Fr(i,n) for(ll i=1;i<=(n);++i)
#define ifr(i,n) for(int i=(n)-1;i>=0;--i)
#define iFr(i,n) for(int i=(n);i>0;--i)
 
 
ll nC2(ll n) {
  return n*(n-1)/2;
} 
 
int main(void) {
  ll n;cin>>n;
  vector<ll> a(n+1, 0);
  Fr(i, n) cin>>a[i];
  fr(i, n) a[i+1] = a[i+1] + a[i];
  sort(a.begin(), a.end());
  ll ans = 0, c = 1;
  a.push_back(-10e10);
  fr(i, n+1) {
    if(a[i] == a[i+1]) c++;
    else {
      ans += nC2(c);
      c=1;
    }
  }

  cout << ans << endl;


  return 0;
}
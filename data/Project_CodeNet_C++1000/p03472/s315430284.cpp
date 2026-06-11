#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
const ll MOD = 1000000007;
// const ll INF = 1000000000000000000LL;

int main() {
  ll n,h;
  cin >> n >> h;
  vector<ll> a(n);
  vector<ll> b(n);
  rep(i,n){
    cin >> a[i] >> b[i];
  }
  sort(b.begin(),b.end(),greater<ll>());
  sort(a.begin(),a.end(),greater<ll>());
  ll s;
  rep(i,n){
    if(a[0]>b[i]){
      s = i;
      break;
    }
  }
  int cnt=0;
  int i=0;
  while(i<s&&i<n){
      h-=b[i];
      i++;
      cnt++;
      if(h<=0)
        break;
  }
  if(h>0){
    cnt+=h/a[0];
    if(h%a[0]) cnt++;
  }
  cout << cnt << endl;
  return 0;
}

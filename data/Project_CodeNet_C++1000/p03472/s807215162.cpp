#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}


ll const mod = 1e9+7;
int main() {
  ll N,H,use,cnt=0;
  cin >> N >> H;
  vector<ll> a(N),b(N);
  rep(i,N) cin >> a[i] >> b[i];
  use = *max_element(a.begin(),a.end());
  sort(b.rbegin(),b.rend());
  for (auto i:b) {
    if (i>use) {
      cnt++;
      H-=i;
      if (H<=0)break;
    }
    else {
      break;
    }
  }
  if (H>0) cnt += (H+use-1)/use;
  cout << cnt << endl;
}
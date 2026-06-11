#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;
const int INF = 1001001001;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  ll costa = 0;
  ll costb = 0;

  rep(i, n) {
    if (a[i] < b[i]) costa += (b[i] - a[i]) / 2;  // 余裕が減る回数
    if (a[i] > b[i]) costb += a[i] - b[i];        // 余裕が増える回数
  }
  if (costb <= costa) cout << "Yes" << endl;
  else cout << "No" << endl;
}
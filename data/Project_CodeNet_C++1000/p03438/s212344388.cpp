#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  ll cnt = 0;
  rep(i, n) {
    if (a[i] < b[i]) {
      cnt += (b[i] - a[i]) / 2;
    } else {
      cnt -= a[i] - b[i];
    }
  }
  if(cnt < 0) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}
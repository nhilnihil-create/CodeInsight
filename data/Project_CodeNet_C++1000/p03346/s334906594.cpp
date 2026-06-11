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
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<int> d(n + 1);
  rep(i, n) {
    d[a[i]] = i;
  }
  int maxlen = 0;
  int len = 0;
  for (int i = 1; i < n; ++i) {
    if (d[i] < d[i + 1]) {
      len++;
    } else {
      len = 0;
    }
    chmax(maxlen, len);
  }

  cout << n - maxlen - 1 << endl;
}
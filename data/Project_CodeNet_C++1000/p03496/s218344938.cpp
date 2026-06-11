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
  vector<int> a(n);
  bool minus = false;
  bool plus = false;
  rep(i, n) {
    cin >> a[i];
    if(a[i] < 0) minus = true;
    if(a[i] > 0) plus = true;
  }
  vector<P> ans;
  if(minus && plus) {
    P maxv = P(a[0], 0);
    P minv = P(a[0], 0);
    rep(i, n) {
      if (maxv.first < a[i]) {
        maxv.first = a[i];
        maxv.second = i;
      }
      if (minv.first > a[i]) {
        minv.first = a[i];
        minv.second = i;
      }
    }

    auto add = [&] (int val, int idx) {
      rep(i, n) {
        ans.push_back(P(idx, i));
      }
    };

    if(abs(maxv.first) > abs(minv.first)) {
      minus = false;
      add(maxv.first, maxv.second);
    } else {
      plus = false;
      add(minv.first, minv.second);
    }
  }
  //処理を書く

  if(minus) {
    for(int i = n - 2; i >= 0; --i) {
      ans.push_back(P(i + 1, i));
    }
  } else if (plus) {
    for(int i = 1; i < n; ++i) {
      ans.push_back(P(i - 1, i));
    }
  }

  cout << ans.size() << endl;
  rep(i, ans.size()) {
    cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
  }
  
}
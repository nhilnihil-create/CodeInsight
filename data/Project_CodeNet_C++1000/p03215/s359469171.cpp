#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr ll INF = (1LL << 55);

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<ll> cum(n+1,0);
  rep(i,n) cum[i + 1] = cum[i] + a[i];

  vector<ll> b;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j <= n; j++) b.emplace_back(cum[j] - cum[i]);
  }

  ll res = 0;

  /*上の桁から決めてく*/
  for (int d = 54; d >= 0; d--) {
    int cnt = 0;
    ll now = res | (1LL << d);/*今の桁を選ぶ場合*/
    /*選択可能か*/
    for (auto e : b) cnt += ((now & e) == now);

    if (cnt >= k) swap(res, now);
  }
  
  cout << res << endl;
  return 0;
} 
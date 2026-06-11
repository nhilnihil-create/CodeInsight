#include<bits/stdc++.h>
#define rep(i,f,n) for(int i=(f); (i) < (n); i++)
#define repe(i,f,n) for(int i=(f); (i) <= (n); i++)
using namespace std;

typedef long long ll;
ll INF = 1LL << 60;

int
main() {

  int n, k; cin >> n >> k;
  vector<ll> dis_cdl(n);
  rep(i, 0, n) cin >> dis_cdl[i];

  ll ans = INF;
  for(int i =  0; i + k - 1 < n; i++){
    ll from_left = dis_cdl[i + k - 1] - dis_cdl[i] + abs(dis_cdl[i]);
    ll from_right = dis_cdl[i + k -1] - dis_cdl[i] + abs(dis_cdl[i + k - 1]);
    ans = min(ans,min(from_left, from_right));
  }

  cout << ans << endl;

  return 0;
}



#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr int INF = 1e9;

int main(){
  int n, q;
  string s;
  cin >> n >> q >> s;
  vector<pair<char, char>> query(q);
  rep(i,q) cin >> query[i].first >> query[i].second;

  auto ok = [&](int now) {
    for (auto p : query) {
      if (s[now] != p.first) continue;
      if (p.second == 'L') now--;
      else now++;
      if (now < 0) return -1;
      if (now >= n) return 1;
    }
    return 0;
  };
  //左側
  int l = -1, r = n;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (ok(m) == -1) l = m;
    else r = m;
  }
  int fl = r;
  l = -1, r = n;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (ok(m) == 1) r = m;
    else l = m;
  }
  int fr = n - l-1;
  cout << n - (fl+fr) << endl;
  return 0;
}

/*
int main(){ 
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<P> p(26);
  vector<int> dist(26,0);
  rep(i,26) p[i].first = 0, p[i].second = 0;
  rep(i,q) {
    char t, d;
    cin >> t >> d;
    int idx = t - 'A';
    if (d == 'L') dist[idx]--;
    else dist[idx]++;
    p[idx].first = min(p[idx].first, dist[idx]);
    p[idx].second = max(p[idx].second, dist[idx]);
  }
  int res = 0;
  vector<int> de(n,0);
  for (int i = 0; i < n; i++) {
    int idx = s[i] - 'A';
    int l = p[idx].first, r = p[idx].second;
    if (i + l < 0 || i + r >= n) de[i] = 1;
    else res++;
  } 
  rep(i,n) cout << de[i] << " ";
  cout << endl;
  cout << res << endl;
  return 0;
} 
*/
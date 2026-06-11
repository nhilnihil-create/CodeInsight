#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mod 1000000007
#define h1 7897897897897897
#define h2 7897466719774591
#define b1 98762051
#define b2 98765431
#define inf 1000000000
#define pi 3.1415926535897932384626
#define LMAX 9223372036854775807
#define ll long long
#define fi first
#define se second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pii>
#define SET(a, b) memset(a, b, sizeof(a));
#define all(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
int n, m, k, t, T, x, y, sum, cnt, h[200005];
ll a[200005], seg[800005], ans;
void update(int id, int l, int r, int pos, ll val) {
  if (l == pos && r == pos) {
    seg[id] = val;
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid) update(id * 2, l, mid, pos, val);
  else update(id * 2 + 1, mid + 1, r, pos, val);
  seg[id] = max(seg[id*2], seg[id*2+1]);
}
ll query(int id, int l, int r, int ql, int qr) {
  if (ql > r || qr < l) return 0;
  if (ql <= l && r <= qr) return seg[id];
  int mid = (l + r) >> 1;
  return max(query(id * 2, l, mid, ql, qr), query(id * 2 + 1, mid + 1, r, ql, qr));
}
int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  FOR(i, 1, n) {
    cin >> h[i];
  }
  FOR(i, 1, n) {
    cin >> a[i];
  }
  FOR(i, 1, n) {
    if (h[i] == 1) {
      update(1, 1, n, h[i], a[i]);
      ans = max(ans, a[i]);
      continue;
    }
    ll maxx = query(1, 1, n, 1, h[i] - 1);
    update(1, 1, n, h[i], maxx + a[i]);
    cerr << maxx  + a[i] <<endl;
    ans = max(ans, maxx + a[i]);
  }
  cout << ans << endl;
  return 0;
}

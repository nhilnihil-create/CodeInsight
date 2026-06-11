// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 2e5 + 5;

int n;
int a[N], h[N];
long long st[N << 2];

long long query(int cur, int s, int e, int l, int r) {
  if(s > r || e < l) return 0;
  if(s >= l && e <= r) return st[cur];
  int mid = (s + e) / 2;
  return max(query(2 * cur + 1, s, mid, l, r), query(2 * cur + 2, mid + 1, e, l, r));
}

void update(int cur, int s, int e, int i, long long dp) {
  if(s > i || e < i) return;
  if(s == e) {
    st[cur] = dp;
    return;
  }
  int mid = (s + e) / 2;
  update(2 * cur + 1, s, mid, i, dp);
  update(2 * cur + 2, mid + 1, e, i, dp);
  st[cur] = max(st[2 * cur + 1], st[2 * cur + 2]);
}

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &h[i]), h[i]--;
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  long long best = 0;
  for(int i = 0; i < n; i++) {
    long long cur = a[i] + query(0, 0, n - 1, 0, h[i]);
    best = max(best, cur);
    update(0, 0, n - 1, h[i], cur);
  }
  cout << best << endl;
  return 0;
}

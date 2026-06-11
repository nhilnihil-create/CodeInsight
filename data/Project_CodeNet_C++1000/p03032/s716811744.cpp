#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
#define limit(x, l, r) max(l, min(x, r))
#define lims(x, l, r) (x = max(l, min(x, r)))
#define isin(x, l, r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)), x.end())
#define show(x) cout << #x << " = " << x << endl;
#define print(x) cout << x << endl;
#define PQ(T) priority_queue<T, v(T), greater<T>>
#define bn(x) ((1 << x) - 1)
#define dup(x, y) (((x) + (y)-1) / (y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;

int main() {
  int n, k;
  cin >> n >> k;
  deque<int> q;
  rep(i, n) {
    int a;
    cin >> a;
    q.push_back(a);
  }

  // m:= toridasu kaisuu
  ll ans = 0;
  for(int m = 1;m<=k;m++) {
    for(int l=0;l<=m;l++) {
      for(int r=0;r<=m-l;r++) {
        deque<int> q2;
        q2 = q;
        priority_queue<int, vi, greater<int>> pq;
        ll sum = 0;
        rep(i, l) {
          if(q2.empty())break;
          sum += q2.front();
          if (q2.front() < 0) pq.push(q2.front());
          q2.pop_front();
        }
        rep(i, r) {
          if(q2.empty())break;
          sum += q2.back();
          if (q2.back() < 0) pq.push(q2.back());
          q2.pop_back();
        }
        rep(i, k - m) {
          if(pq.empty())break;
          sum -= pq.top();
          pq.pop();
        }
        maxs(ans, sum);
      }
    }
  }
  print(ans);
  return 0;
}
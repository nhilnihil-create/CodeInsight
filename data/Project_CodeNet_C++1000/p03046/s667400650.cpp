#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define vd vector<ld>
#define vvd vector<vector<ld>>
#define ALL(a) begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)
#define SORT(a) stable_sort(ALL(a))
#define RSORT(a) stable_sort(RALL(a))
#define REV(a) reverse(ALL(a))
#define UNIQUE(a) a.erase(unique(ALL(a)), end(a))
#define lambda(i) [](auto& i)
#define compare(i, j) [](auto& i, auto& j)
#define min_of(a) *min_element(ALL(a))
#define max_of(a) *max_element(ALL(a))
#define sum(a) accumulate(ALL(a), 0)
#define pb push_back
#define mp make_pair
#define SZ(a) ll((a).size())
#define REP(i, n) for (decltype(+n) i = 0; i < (n); i++)
#define RREP(i, n) for (auto i = n - 1; i != static_cast<decltype(i)>(-1); i--)
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define RFOR(i, a, b) for (auto i = b - 1; i != a; i--)
#define EACH(i, a) for (auto&& i: (a))
using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

struct union_find {
  vector<ll> data;
  union_find(ll size) : data(size, -1) { }
  bool union_set(ll x, ll y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool find_set(ll x, ll y) {
    return root(x) == root(y);
  }
  ll root(ll x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  ll size(ll x) {
    return -data[root(x)];
  }
};

vi cum(vi V) {
  vi U(SZ(V));
  partial_sum(ALL(V), begin(U));
  return U;
}

void solve() {
  ll m, k;
  ll ans = 0;

  cin >> m >> k;
  ll a = 1 << m;
  if (k >= a) {
    cout << -1 << endl;
  } else if (m == 1) {
    cout << (k == 0 ? "0 0 1 1" : "-1") << endl;
  } else {
    REP(i, a) {
      if (i != k) cout << i << " ";
    }
    cout << k << " ";
    RREP(i, a) {
      if (i != k) cout << i << " ";
    }
    cout << k << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(15);
  solve();
}

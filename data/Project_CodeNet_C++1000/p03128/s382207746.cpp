#pragma region header
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ld long double
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vs vector<string>
#define vvs vector<vector<string>>
#define vvvs vector<vector<vector<string>>>
#define vd vector<ld>
#define vvd vector<vector<ld>>
#define vvvd vector<vector<vector<ld>>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vvvb vector<vector<vector<bool>>>
#define pii pair<int, int>
#define vp vector<pair<int, int>>
#define vvp vector<vector<pair<int, int>>>
#define vvvp vector<vector<vector<pair<int, int>>>>
#define mii map<int, int>
#define vm vector<map<int, int>>
#define vvm vector<map<pair<int, int>>>
#define vvvm vector<vector<vector<map<int, int>>>>
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define SORT(a) stable_sort(all(a))
#define RSORT(a) stable_sort(rall(a))
#define rev(a) reverse(all(a))
#define uniq(a) a.erase(unique(all(a)), end(a))
#define lambda(i) [=](auto i)
#define compare(i, j) [=](auto i, auto j)
#define min_of(a) *min_element(all(a))
#define max_of(a) *max_element(all(a))
#define sum_of(a) accumulate(all(a), 0)
#define count_of(a, i) count(all(a), i)
#define lower_index(a, i) (lower_bound(all(a), i) - begin(a)) // use member func for set
#define upper_index(a, i) (upper_bound(all(a), i) - begin(a))
#define binary(a, i) binary_search(all(a), i)
#define exists(a, i) (find(all(a), i) != end(a))
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define sz(a) (int)(a).size()
#define rep1(i, n) for (decltype(+n) i = 0; i < (n); i++)
#define rrep1(i, n) for (auto i = n - 1; i != static_cast<decltype(i)>(-1); i--)
#define rep2(i, a, b) for (auto i = (a); i < (b); i++)
#define rrep2(i, a, b) for (auto i = b - 1; i >= a; i--)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep2, rep1) (__VA_ARGS__)
#define rrep(...) GET_MACRO(__VA_ARGS__, rrep2, rrep1) (__VA_ARGS__)
#define each(i, a) for (auto &&i : (a))
#define split_pair(f, s, p) auto f = p.first; auto s = p.second
using namespace std;

const int INF = 1e18;
const int MOD = 1e9 + 7;
int mod(int A) { return (A % MOD + MOD) % MOD; }
int m_add(int A, int B) { return (A + B) % MOD; }
int m_add(int A, int B, int C) { return (A + B + C) % MOD; }
int m_sub(int A, int B) { return (A + MOD - B) % MOD; }
int m_mul(int A, int B) { return A * B % MOD; }
int m_mul(int A, int B, int C) { return A * B % MOD * C % MOD; }
int m_bipow(int X, int Y) {
  if (Y == 0) return 1;
  else if (Y == 1) return X % MOD;
  else if (Y % 2 == 0) {
    int Z = m_bipow(X, (int)(Y / 2));
    return m_mul(Z, Z);
  } else {
    int Z = m_bipow(X, (int)(Y / 2));
    return m_mul(Z, Z, X);
  }
}
int m_inv(int X) { return m_bipow(X, MOD - 2); }
int m_div(int A, int B) { return m_mul(A, m_inv(B)); }

template <class T>
void COUT(T A) { cout << A << endl; }

template <class T>
bool amin(T &A, T B) {
  if (A > B) {
    A = B;
    return true;
  }
  return false;
}
template <class T>
bool amax(T &A, T B) {
  if (A < B) {
    A = B;
    return true;
  }
  return false;
}

template <class T>
vector<pair<T, int>> indexed_vector(vector<T> V) {
  int N = sz(V);
  vector<pair<T, int>> W(N);
  for (int i = 0; i < N; i++) W[i] = make_pair(V[i], i);
  return W;
}

template <class T, class S>
vector<pair<T, S>> zip(vector<T> V, vector<S> W) {
  int N = min(sz(V), sz(W));
  vector<pair<T, S>> X(N);
  for (int i = 0; i < N; i++) X[i] = make_pair(V[i], W[i]);
  return X;
}
template <class T, class S>
pair<vector<T>, vector<S>> unzip(vector<pair<T, S>> V) {
  int N = sz(V);
  auto W = make_pair(vector<T>(N), vector<S>(N));
  for (int i = 0; i < N; i++) {
    W.first[i] = V[i].first;
    W.second[i] = V[i].second;
  }
  return W;
}

vs split(const string& S, string D) {
  vs elms;
  size_t offset = 0, d_size = D.size();
  while (true) {
    size_t next = S.find_first_of(D, offset);
    if (next == string::npos) {
      elms.push_back(S.substr(offset));
      return elms;
    }
    elms.push_back(S.substr(offset, next - offset));
    offset = next + d_size;
  }
}
vs split(const string& S, char D) { return split(S, string(1, D)); }
string join(const vs& V, const string D = "") {
  string s;
  if (!V.empty()) {
    s += V[0];
    for (size_t i = 1, c = V.size(); i < c; ++i) {
      if (!D.empty()) s += D;
      s += V[i];
    }
  }
  return s;
}
string join(const vs& V, const char D) { return join(V, string(1, D)); }

vi divisors(int N) {
  vi ret;
  for (int i = 1; i * i <= N; i++) {
    if (N % i == 0) {
      ret.pb(i);
      if (i * i != N) ret.pb(N / i);
    }
  }
  SORT(ret);
  return ret;
}

mii prime_factors(int N) {
  mii ret;
  for (int i = 2; i * i <= N; i++) {
    while (N % i == 0) {
      ret[i]++;
      N /= i;
    }
  }
  if (N != 1) ret[N]++;
  return ret;
}

int ceil_div(int X, int Y) { return (X - 1) / Y + 1; }

vi cum(vi V) {
  vi U(sz(V));
  partial_sum(all(V), begin(U));
  return U;
}

struct union_find {
  vi data;
  union_find(int size) : data(size, -1) {}
  bool union_set(int x, int y) {
    x = root(x);
    y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y];
      data[y] = x;
    }
    return x != y;
  }
  bool find_set(int x, int y) { return root(x) == root(y); }
  int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
  int size(int x) { return -data[root(x)]; }
};

// struct combination {
//   vi fact, ifact;
//   combination(int n): fact(n + 1), ifact(n + 1) {
//     assert(n < MOD);
//     fact[0] = 1;
//     for (int i = 1; i <= n; ++i) fact[i] = m_mul(fact[i - 1], i);
//     ifact[n] = m_inv(fact[n]);
//     for (int i = n; i >= 1; --i) ifact[i-1] = m_mul(ifact[i], i);
//   }
//   int operator()(int n, int k) {
//     if (k < 0 || k > n) return 0;
//     return m_mul(fact[n], ifact[k], ifact[n - k]);
//   }
// } comb(200001);
#pragma endregion header

// MOD = 1e9 + 7;


void solve(int n, int m, vi a) {
  vi costs = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  mii c_d;
  each(i, a) {
    amax(c_d[costs[i]], i);
  }
  vp vpcd;
  for(auto& p: c_d)vpcd.push_back(mp(p.second, p.first));
  RSORT(vpcd);
  vi dp(n + 1, -INF);
  dp[0] = 0;
  rep(i, 1, n + 1){
    for(auto p: vpcd) {
      if(i >= p.second) {
        amax(dp[i], dp[i - p.second] + 1);
      }
    }
    if(dp[i] <= 0)dp[i] = -INF;
  }
  while(n > 0) {
    for(auto& p: vpcd) {
      if(n >= p.second && dp[n - p.second] == dp[n] - 1) {
        cout << p.first;
        n -= p.second;
        break;
      }
    }
  }
  cout << endl;
}


#pragma region main
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(15);

  int n;
  cin >> n;
  int m;
  cin >> m;
  vi a(m);
  for(int i = 0 ; i < m ; i++){
    cin >> a[i];
  }
  solve(n, m, move(a));
}
#pragma endregion main

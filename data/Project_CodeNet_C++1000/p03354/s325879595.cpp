#include "bits/stdc++.h"
using namespace std;

#define ASC(vec) vec.begin(), vec.end()    // 昇順ソート 例：sort(ASC(vec));
#define DESC(vec) vec.rbegin(), vec.rend() // 降順ソート 例：sort(DESC(vec));
#define rep(i, n) for (int i = 0; i < (n); i++)
#define Rep(i, n) for (int i = 1; i < n; i++)
#define REP(i, vec) for (auto i = vec.begin(); i != vec.end(); ++i)

const int       mod = 1000000007;
const int       inf = (1 << 21);
const long long INF = 1LL << 60;

using ii = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vd = vector<double>;
using vb = vector<bool>;
using vl = vector<ll>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvb = vector<vector<bool>>;
using vii = vector<pair<int, int>>;
using vll = vector<pair<ll, ll>>;

template<class T>
inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T>
inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T>
inline T GCD(T a, T b) { return b ? GCD(b, a % b) : a; }
template<class T>
inline T LCM(T a, T b) { return (a + (b - 1)) / b; }
template<class T>
inline T round_int(T a, T b) {return (a + (b - 1)) / b; }

constexpr array<int, 9> dx = { 0, 1, 0, -1, -1, 1, 1, -1, 0 };
constexpr array<int, 9> dy = { 1, 0, -1, 0, 1, 1, -1, -1, 0 };

// ──────────────────────────────────────────────────────────────────

class UnionFind {
private:
    int n;
    vector<int> a;
public:
    UnionFind(int n) : n(n), a(n, -1) {}
    int find(int x) { return a[x] < 0 ? x : (a[x] = find(a[x])); }
    bool same(int x, int y) { return find(x) == find(y); }
    bool same(ii& p) { return same(p.first, p.second); }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (a[x] > a[y]) swap(x, y);
        a[x] += a[y];
        a[y] = x;
        n--;
        return true;
    }
    bool unite(ii& p) { return unite(p.first, p.second); }
    int size() const { return n; }
    int size(int x) { return -a[find(x)]; }
};

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> p(n);
	rep(i, n) cin >> p[i];

    UnionFind uf(n + 1);

    rep(i, m) {
        int x, y;
        cin >> x >> y;

        uf.unite(x, y);
    }

    int ans = 0;
    rep(i, n) {
        if (uf.same(i + 1, p[i])) ans++;
    }
    cout << ans << endl;
}
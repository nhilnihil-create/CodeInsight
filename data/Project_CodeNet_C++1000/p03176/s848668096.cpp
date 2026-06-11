#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;
constexpr long long LINF = 1e18;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;

template<class T>
class SegmentTree {
    using Func = std::function<T(T, T)>;
    private:
        const Func F;
        const T DEF;
        int N;
        std::vector<T> dat;
    public:
        SegmentTree(int n, const Func f, const T def) : F(f), DEF(def) {
            N = 1;
            while (N < n) N *= 2;
            dat.assign(2*N, DEF);
        }
        // a is 0-indexed
        void set(int a, const T v) { dat[a+N] = v; }
        void build() { for (int i=N-1; i>0; --i) dat[i] = F(dat[2*i], dat[2*i+1]); }
        // a is 0-indexed
        void update(int a, const T v) {
            int cur = a + N;
            dat[cur] = v;
            while ((cur /= 2) > 0) dat[cur] = F(dat[2*cur], dat[2*cur+1]);
        }
        // return value of [a, b)
        // a and b are 0-indexed
        T get(int a, int b) const { return get(a, b, 1, 0, N); }
        T get(int a, int b, int k, int l, int r) const {
            if (b <= l || r <= a) return DEF;
            if (a <= l && r <= b) return dat[k];
            T vleft = get(a, b, 2*k, l, (l+r)/2);
            T vright = get(a, b, 2*k+1, (l+r)/2, r);
            return F(vleft, vright);
        }
        // a is 0-indexed
        T at(int a) const { return dat.at(a+N); }
};

void solve() {
    int N;
    cin >> N;
    vector<int> h(N), a(N);
    for (int i=0; i<N; ++i) cin >> h[i];
    for (int i=0; i<N; ++i) cin >> a[i];

    for (int i=0; i<N; ++i) --h[i];
    SegmentTree<ll> st(N, [](ll a, ll b){return max(a, b);}, 0);
    for (int i=0; i<N; ++i) st.update(h[i], st.get(0, h[i]) + a[i]);
    cout << st.get(0, N) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}

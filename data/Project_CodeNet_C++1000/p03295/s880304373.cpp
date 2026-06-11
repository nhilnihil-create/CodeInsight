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
        void set(int a, const T v) {
            dat.at(a+N) = v;
        }
        void build() {
            for (int i=N-1; i>0; --i) dat.at(i) = F(dat.at(2*i), dat.at(2*i+1));
        }
        // a is 0-indexed
        void update(int a, const T v) {
            int cur = a + N;
            dat.at(cur) = v;
            while ((cur /= 2) > 0) dat.at(cur) = F(dat.at(2*cur), dat.at(2*cur+1));
        }
        // return value of [a, b)
        // a and b are 0-indexed
        T get(int a, int b) {
            return get(a, b, 1, 0, N);
        }
        T get(int a, int b, int k, int l, int r) {
            if (b <= l || r <= a) return DEF;
            if (a <= l && r <= b) return dat.at(k);
            T vleft = get(a, b, 2*k, l, (l+r)/2);
            T vright = get(a, b, 2*k+1, (l+r)/2, r);
            return F(vleft, vright);
        }
        // a is 0-indexed
        T at(int a) { return dat.at(a+N); }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> p(m);
    for (int i=0; i<m; ++i) {
        cin >> p.at(i).first >> p.at(i).second;
    }

    sort(p.begin(), p.end(), greater<pair<int, int>>());
    int res = 0, rm = n;
    for (int i=0; i<m; ++i) {
        if (rm >= p.at(i).second) {
            ++res;
            rm = p.at(i).first;
        }
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define REP(var, n)  for (int var = 0; var < (n); var++)
#define RREP(var, n)  for (auto var = n - 1; var != static_cast<int>(-1); var--)
#define FOR(var, a, b)  for (auto var = (a); var < (b); var++)
#define RFOR(var, a, b)  for (auto var = b - 1; var != a; var--)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pii;

#define all(c) begin(c),end(c)

#define D(x) do { std::cerr << x << " "; } while (0)
#define D2(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)


template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
    if (!v.empty()) {
        out << '[';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "\b\b]";
    }
    return out;
}


template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    return os << '(' << p.first << ',' << p.second << ')';
}


template<class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

struct BLK {
    int w;
    int s;
    int v;
};

bool cmp(BLK lhs, BLK rhs) { return lhs.w + lhs.s < rhs.w + rhs.s; }

ll solve() {
    int N;
    cin >> N;
    vector<BLK> block(N);
    REP(i, N) {
        int w, s, v;
        cin >> w >> s >> v;
        block[i] = BLK{w, s, v};
    }

    sort(all(block), cmp);

    int MX_W = 10010;
    vll dp(MX_W, 0);
    REP(i, N) {
        RREP(j, block[i].s + 1) {
            int ni = min(j + block[i].w, MX_W - 1);
            chmax(dp[ni], dp[j] + block[i].v);
        }
    }

    return *max_element(all(dp));
}


int main() {
    cout.precision(30);
    cin.tie(0);
    ios::sync_with_stdio(false);

//    cout << (solve() ? "Heisei" : "TBD") << endl;
//    cout << (solve() ? "YES" : "NO") << endl;
    cout << solve() << endl;
//    solve();

    return 0;
}
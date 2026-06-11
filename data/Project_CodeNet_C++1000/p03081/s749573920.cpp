#include <bits/stdc++.h>
using namespace std;

#define REP(i, m, n) for (int i = (m); i < (int)(n); i++)
#define REPS(i, m, n) for (int i = (m); i <= (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define reps(i, n) for (int i = 0; i <= (int)(n); i++)
#define rrep(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define rreps(i, x) for (int i = (int)(x); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> P;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9 + 7;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename A, size_t N, typename T> void Fill(A (&array)[N], const T &val) { fill( (T*)array, (T*)(array+N), val ); }


int simulate (const string &s, const vector<pair<char, char>> &td, int pos) {
    for (auto c : td) {
        if (s[pos] != c.fi) continue;
        if (c.se == 'L') --pos;
        else ++pos;
        if (pos < 0) return -1;
        if (pos >= (int)s.size()) return 1;
    }
    return 0;
}

int solve(int N, const string &s, const vector<pair<char, char>> &td) {
    int low = -1, high = N;
    while (high - low > 1) {
        int mid = (low + high) / 2;
        if (simulate(s, td, mid) == -1) low = mid;
        else high = mid;
    }
    int left_fall = high;
    low = -1, high = N;
    while (high - low > 1) {
        int mid = (low + high) / 2;
        if (simulate(s, td, mid) == 1) high = mid;
        else low = mid;
    }
    int right_fall = N - 1 - low;
    return N - (left_fall + right_fall);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, Q;
    string s;
    cin >> N >> Q >> s;
    vector<pair<char, char>> td(Q);
    rep(i, Q) {
        cin >> td[i].fi >> td[i].se;
    }
    cout << solve(N, s, td) << endl;
    return 0;
}
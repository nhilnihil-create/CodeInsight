#include <bits/stdc++.h>
using namespace std;

struct Benri { Benri() { std::cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(12);}} benri;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vll = vector<long long>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

template <typename T> using PQ = priority_queue<T>;
template <typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define F first
#define S second

template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }

constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr double EPS = 1e-10;
constexpr int INF = 1001001001;
//constexpr ll INF = 1001001001001001001ll;


int H, W, N;
int ix, iy;
string S, T;

bool solve() {
    // left, right
    int left = 0, right = W;
    if (S[N - 1] == 'L') ++left;
    if (S[N - 1] == 'R') --right;
    for (int i = N - 2; i >= 0; --i) {
        if (T[i] == 'L') right = min(right + 1, W);
        else if (T[i] == 'R') left = max(0, left - 1);
        if (S[i] == 'L') left = left + 1;
        else if (S[i] == 'R') right = right - 1;
        if (left >= right) return false;
    }
    if (iy < left || iy >= right) return false;

    // up, down
    left = 0, right = H;
    if (S[N - 1] == 'U') ++left;
    if (S[N - 1] == 'D') --right;
    for (int i = N - 2; i >= 0; --i) {
        if (T[i] == 'U') right = min(right + 1, H);
        else if (T[i] == 'D') left = max(0, left - 1);
        if (S[i] == 'U') left = left + 1;
        else if (S[i] == 'D') right = right - 1;
        if (left >= right) return false;
    }
    if (ix < left || ix >= right) return false;

    return true;
}

int main() {
    while (cin >> H >> W >> N >> ix >> iy >> S >> T) {
        --ix, --iy;
        cout << (solve() ? "YES" : "NO") << endl;
    }
}
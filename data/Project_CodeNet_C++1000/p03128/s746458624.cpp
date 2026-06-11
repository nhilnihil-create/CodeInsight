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
constexpr int INF = 1001001001;
//constexpr ll INF = 1001001001001001001ll;
constexpr double EPS = 1e-10;
using number = long long;

vector<string> dp;
int N, M;
int mh[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int A[9];

string rec(int n) {
    if (dp[n] != "a") return dp[n];

    string res = "b";

    int sz = 2;
    rep(i, M) {
        if (n < mh[A[i]]) continue;
        string t = rec(n - mh[A[i]]);
        if (sz <= t.size()) {
            sz = t.size();
            res = to_string(A[i]) + t;
        }
    }

    dp[n] = res;
    return res;
}

int main() {
    cin >> N >> M;
    rep(i, M) {
        cin >> A[i];
    }
    sort(A, A + M);

    dp.assign(10005, "a");
    dp[0] = "aa";

    string s = rec(N);
    int x = s.size();
    s = s.erase(x - 2);

    cout << s << endl;

}
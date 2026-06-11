#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
void print() { cout << "\n"; }
template <class T> void print(const T &x) { cout << x << "\n"; }
template <class T, class... Args> void print(const T &x, const Args &... args) {
    cout << x << " ";
    print(args...);
}
template <class T> void printVector(const vector<T> &v) {
    for(const T &x : v) {
        cout << x << " ";
    }
    cout << "\n";
}
using ll = long long;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
constexpr int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int N, A, B, C;
vector<int> l;

int dfs(int i, int a, int b, int c) {
    if(i == N) {
        if(a == 0 || b == 0 || c == 0) {
            return INF;
        }
        return abs(A - a) + abs(B - b) + abs(C - c);
    }
    int res = INF;
    chmin(res, dfs(i + 1, a + l[i], b, c) + (a == 0 ? 0 : 10));
    chmin(res, dfs(i + 1, a, b + l[i], c) + (b == 0 ? 0 : 10));
    chmin(res, dfs(i + 1, a, b, c + l[i]) + (c == 0 ? 0 : 10));
    chmin(res, dfs(i + 1, a, b, c));
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> A >> B >> C;
    l.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> l[i];
    }
    print(dfs(0, 0, 0, 0));
}
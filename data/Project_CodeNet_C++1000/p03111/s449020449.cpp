#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}
const int INF = 1001001001;
int n, A, B, C;
vi l(8);

int dfs (int cur, int a, int b, int c) {
    if (cur == n) {
        if (a != 0 && b != 0 && c != 0) return abs(A-a) + abs(B-b) + abs(C-c);
        else return INF;
    }
    int res1 = dfs(cur+1, a, b, c);
    int res2 = dfs(cur+1, a + l[cur], b, c) + 10 * (a != 0);
    int res3 = dfs(cur+1, a, b + l[cur], c) + 10 * (b != 0);
    int res4 = dfs(cur+1, a, b, c + l[cur]) + 10 * (c != 0);
    return min({res1, res2, res3, res4});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> A >> B >> C;
    rep(i, n) cin >> l[i];
    cout << dfs(0, 0, 0, 0) << endl;
}
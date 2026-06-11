#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i, a, b) for(ll i = (a); i < (ll)b; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1000000000000000
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;
typedef pair<ll, ll> p;
constexpr int MOD = 1000000007;
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

void print(const std::vector<int> &v) {
    std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << " "; });
    std::cout << std::endl;
}
int N, M;
vector<int> E[101010];
int C[101010];
int num[2];

void dfs(int cur, int col) {
    if(C[cur] != -1) {
        if(C[cur] != col) {
            //二部グラフではない
            // cout << cur << C[cur] << col << endl;
            cout << 1LL * N * (N - 1) / 2 - M << endl;
            exit(0);
        }
    } else if(C[cur] == -1) {
        C[cur] = col;
        num[col]++;
        for(auto e : E[cur]) {
            dfs(e, col ^ 1);
        }
    }
}
int main() {
    cin >> N >> M;
    vector<int> A(M), B(M);
    REP(i, M) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }
    memset(C, -1, sizeof(C));
    REP(i, 101010) C[i] = -1;
    REP(i, M) {
        E[A[i]].push_back(B[i]);
        E[B[i]].push_back(A[i]);
    }
    dfs(0, 0);
    // cout << "hoge" << endl;
    cout << 1LL * num[0] * num[1] - M << endl;
}
// http://kmjp.hatenablog.jp/entry/2017/10/09/0900
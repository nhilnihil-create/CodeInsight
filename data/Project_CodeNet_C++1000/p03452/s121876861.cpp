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
vector<vector<pair<int, int>>> al(100000);
vector<bool> visited(100000, false);
vector<long long> dist(100000, INF * -1);
//深さ優先
bool dfs(int i, int d) {
    if(visited[i] && d != dist[i])
        return false;
    if(visited[i] && d == dist[i])
        return true;
    visited[i] = true;
    dist[i] = d;
    REP(j, al[i].size()) {
        if(!dfs(al[i][j].first, d + al[i][j].second))
            return false;
    }
    return true;
}
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> L(M), R(M), D(M);
    REP(i, M) {
        cin >> L[i] >> R[i] >> D[i];
        L[i]--;
        R[i]--;
        al[L[i]].push_back(make_pair(R[i], D[i]));
        al[R[i]].push_back(make_pair(L[i], -D[i]));
    }
    REP(i, N) {
        if(!visited[i]) {
            //まだ訪れてないので距離が定まっていない
            if(!dfs(i, 0)) {
                // 0にしていいのか？
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
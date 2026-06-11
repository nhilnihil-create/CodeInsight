#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double Double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// chmax, chmin
template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

const string YES = "Yes";
const string NO = "No";

vector<pair<ll, ll>> g[100010];

int d[100010];
int X[100010];
bool v[100010];

void dfs(int root, ll d) {
    if (v[root]) return;
    v[root] = true;
    X[root] = d;
    for (auto e : g[root]) {
        dfs(e.first, d + e.second);
    }
}

void solve(long long N, long long M, std::vector<long long> L,
           std::vector<long long> R, std::vector<long long> D) {

    for (int i = 0; i < M; i++) {
        L[i]--;
        R[i]--;
        g[L[i]].push_back({R[i], D[i]});
        g[R[i]].push_back({L[i], -D[i]});
    }
    for (int i = 0; i < N; i++)
        dfs(i, 0);
    for(int i = 0 ; i < M ; i++){
        if( X[R[i]] - X[L[i]] != D[i]){
            cout << NO << endl;
            return;
        }
    }
    cout << YES << endl;


}

int main() {
    long long N;
    scanf("%lld", &N);
    long long M;
    scanf("%lld", &M);
    std::vector<long long> L(M);
    std::vector<long long> R(M);
    std::vector<long long> D(M);
    for (int i = 0; i < M; i++) {
        scanf("%lld", &L[i]);
        scanf("%lld", &R[i]);
        scanf("%lld", &D[i]);
    }
    solve(N, M, std::move(L), std::move(R), std::move(D));
    return 0;
}

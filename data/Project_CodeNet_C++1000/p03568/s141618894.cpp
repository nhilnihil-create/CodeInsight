#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N;
vector<ll> A;
ll ans = 0;

void dfs(int i, vector<ll> v) {
    if (i >= N) {
        rep(j, v.size()) {
            if (v[j] % 2 == 0) {
                ans++;
                return;
            }
        }
        return;
    }

    v[i] = A[i];
    dfs(i + 1, v);


    v[i] = A[i] - 1;
    dfs(i + 1, v);

    v[i] = A[i] + 1;
    dfs(i + 1, v);
}

int main() {
    cin >> N;
    A.resize(N);
    rep(i, N) cin >> A[i];
    vector<ll> tmp(N);
    dfs(0, tmp);

    cout << ans << endl;
}
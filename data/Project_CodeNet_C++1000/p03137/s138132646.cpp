#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<int>> vv;
typedef pair<int, int> P;

// input
int N, M;
vector<int> X;


void input() {
    cin >> N >> M;
    X = vector<int>(M);
    rep(i, M) cin >> X[i];
}


int main() {
    input();
    sort(X.begin(), X.end());
    vector<int> d(M - 1);
    rep(i, M - 1) d[i] = X[i + 1] - X[i];
    sort(d.begin(), d.end());
    ll ans = 0;
    rep(i, M - N) ans += d[i];
    cout << ans << endl;
}

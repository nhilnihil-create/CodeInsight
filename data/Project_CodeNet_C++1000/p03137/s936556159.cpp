#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> X(M);
    rep(i,M) cin >> X.at(i);
    int ans = 0;
    vector<int> dist(M-1);
    sort(X.begin(), X.end());
    rep(i,M-1) {
        dist.at(i) = X.at(i + 1) - X.at(i);
    }
    sort(dist.begin(), dist.end());
    if (N < M) {
        rep(i,M-N) {
            ans += dist.at(i);
        }
    }
    cout << ans << endl;
}

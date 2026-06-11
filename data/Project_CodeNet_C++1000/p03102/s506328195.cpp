#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int N, M, C;
    cin >> N >> M >> C;
    vector<int> B(M);
    vector<vector<int>> A(N, vector<int> (M));
    rep(i,M) cin >> B.at(i);
    rep(i,N) rep(j,M) cin >> A.at(i).at(j);

    int ans = 0;
    rep(i,N) {
        int sum = 0;
        rep(j,M) sum += A.at(i).at(j) * B.at(j);
        if (sum + C > 0) ++ans;
    }
    cout << ans << endl;
}


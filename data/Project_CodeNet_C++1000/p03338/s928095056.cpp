#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int N;
    string S;
    cin >> N >> S;
   int ans = 0;
    rep(i,N-1) {
        map<int, int> X, Y;
        int cnt = 0;
        for (int j = 0; j < i + 1; ++j) ++X[S.at(j)];
        for (int j = i + 1; j < N; ++j) ++Y[S.at(j)];
        for (auto x : X) {
            if (Y[x.first] > 0) ++cnt;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}

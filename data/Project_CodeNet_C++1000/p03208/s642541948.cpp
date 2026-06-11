#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int N, K;
    cin >> N >> K;
    vector<int> h(N);
    rep(i,N) cin >> h.at(i);
    int ans = INFINITY;
    sort(h.begin(), h.end());
    rep(i,N-K+1) ans = min(ans, h.at(i+K-1) - h.at(i));
    cout << ans << endl;
}

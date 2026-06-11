#include <bits/stdc++.h>
using namespace std;

using Data = tuple<int64_t, int64_t, int64_t>;

const int MAX_N = 1e3;
const int MAX_W = 1e4;
const int MAX_S = 1e4;

int64_t dp[MAX_W + MAX_S + 1];

int main() {
    #ifdef DEBUG
    std::ifstream in("/home/share/inputf.in");
    std::cin.rdbuf(in.rdbuf());
    #endif
    int N;
    cin >> N;
    // (s + w, w, v)
    vector<Data> swv(N);
    for(int w = 0; w <= MAX_W + MAX_S; w++) {
        dp[w] = 0;
    }
    for(int i = 0; i < N; i++) {
        int64_t s, w, v;
        cin >> w >> s >> v;
        swv[i] = Data(s + w, w, v);
    }
    sort(swv.begin(), swv.end());
    for(int i = 0, b = 0; i < N; i++, b = i & 1) {
        int64_t s, w, v;
        tie(s, w, v) = swv[i];
        for(int W = s; W >= w; W--) {
            dp[W] = max(dp[W - w] + v, dp[W]);
        }
    }
    int64_t ans = 0;
    for(int w = 0; w <= MAX_S + MAX_W; w++) {
        ans = max(ans, dp[w]);
    }
    cout << ans << endl;
    return 0;
}
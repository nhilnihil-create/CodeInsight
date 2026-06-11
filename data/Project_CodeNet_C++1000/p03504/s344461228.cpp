#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
typedef long long int64;

int main() {
    int N, C;
    cin >> N >> C;
    using P = pair<int, pair<int, int>>; // 時刻, イベントタイプ, チャンネル
    priority_queue<P, vector<P>, greater<P>> que;
    rep(i, N) {
        int s, t, c;
        cin >> s >> t >> c;
        s *= 2, t *= 2, --c;
        que.push(P(s, {0, c}));
        que.push(P(t, {1, c}));
    }
    int ans = 0, now = 0;
    vector<int> channel(C);
    while(!que.empty()) {
        auto p = que.top();
        que.pop();
        int t = p.first;
        int type, c;
        tie(type, c) = p.second;
        if(type) { // 終了クエリ
            if(--channel[c] == 0) --now;
        } else { // 開始クエリ
            if(channel[c]++ == 0) ++now;
        }
        ans = max(ans, now);
    }
    cout << ans << '\n';
    return 0;
}

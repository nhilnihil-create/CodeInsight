#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int, int>;

int main() {
    int N, K; cin >> N >> K;
    priority_queue<Pair> sushi; // (おいしさ, ネタ)
    priority_queue<Pair, vector<Pair>, greater<Pair>> que;
    for(int i = 0; i < N; ++i) {
        int t, d; cin >> t >> d; t--;
        sushi.emplace(d, t);
    }

    int cnt = 0;
    int64_t ans = 0, x = 0, sum = 0;
    map<int, int> ma;

    // まず、おいしさが大きい順に K 個選ぶ
    // その後、種類数が増加する場合のみを考える
    while(!sushi.empty()) {
        int d, t; tie(d, t) = sushi.top(); sushi.pop(); // 追加候補
        if(que.size() + cnt < K) {
            if(ma[t]++ == 0) x++, cnt++; // 1 個目(必ず選ぶ)
            else que.emplace(d, t); // 2 個目以降
            sum += d;
        } else {
            if(que.empty()) break;
            int cd, ct; tie(cd, ct) = que.top(); // 取り除く候補
            if(ma[t]) continue;
            que.pop();
            sum -= cd;
            ma[t]++, x++, cnt++;
            sum += d;
        }
        ans = max(ans, sum + x * x);
    }
    cout << ans << '\n';
    return 0;
}

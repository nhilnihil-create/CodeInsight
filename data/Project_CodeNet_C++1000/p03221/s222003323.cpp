#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
pair<int, pair<int, int>> p[100010];
int main() {
    cin >> N >> M;
    for(int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        p[i] = make_pair(b, make_pair(a, i));
    }

    sort(p, p + M);
    int cnt[100010] = {};
    pair<int, int> ans[100010];
    for(int i = 0; i < M; ++i) {
        cnt[p[i].second.first]++;
        ans[p[i].second.second] = make_pair(p[i].second.first, cnt[p[i].second.first]);
    }
    for(int i = 0; i < M; ++i) {
        printf("%06d%06d\n", ans[i].first, ans[i].second);
    }
}

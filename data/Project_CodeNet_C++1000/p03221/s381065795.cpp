#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    int N, M;
    cin >> N >> M;
    vector<tuple<int, int, int>> v(M);
    for(int i = 0; i < M; i++) {
        int P, Y;
        cin >> P >> Y;
        v[i] = make_tuple(Y, P, i);
    }
    sort(v.begin(), v.end());

    int cnt[N];
    for(int i = 0; i < N; i++) cnt[i] = 0;
    vector<pair<int, string>> ans(M);
    for(int i = 0; i < M; i++) {
        int p = get<1>(v[i]);
        int num = get<2>(v[i]);

        cnt[p - 1]++;
        ostringstream ss;
        ss << setw(6) << setfill('0') << p;
        ss << setw(6) << setfill('0') << cnt[p - 1];
        string t(ss.str());

        ans[i] = {num, t};
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < M; i++) {
        cout << ans[i].second << "\n";
    }
    return 0;
}

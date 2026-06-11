#include <bits/stdc++.h>
#define INF 1e9
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define FORE(i, a, b) for (int i = (a), e = (b); i < e; ++i)
#define RFORE(i, a, b) for (int i = (b)-1, e = (a); i >= e; --i)
#define ALL(x) (x).begin(), (x).end()
#define SORT(c) sort((c).begin(), (c).end())
#define SORTR(c) sort((c).begin(), (c).end(), greater<int>())
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    map<int, int> ball;
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        ++ball[A];
    }
    if (ball.size() <= K) {
        cout << 0 << endl;
        exit(0);
    }
    using pair_type = pair<int, int>;
    vector<pair_type> v(ALL(ball));
    sort(ALL(v), [](const pair_type& p1, const pair_type& p2) {
        return p1.second < p2.second;
    });
    int ans = 0;
    int len = v.size();
    FOR(i, 0, len) {
        if (len - i <= K) {
            cout << ans << endl;
            exit(0);
        }
        ans += v.at(i).second;
    }
    cout << ans << endl;
}

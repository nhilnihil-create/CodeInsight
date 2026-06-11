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
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> t(N);
    vector<int> x(N);
    vector<int> y(N);
    for (int i = 0; i < N; i++) {
        cin >> t.at(i) >> x.at(i) >> y.at(i);
    }
    int tmp_t = 0;
    int tmp_x = 0;
    int tmp_y = 0;
    FOR(i, 0, N) {
        int t_diff = t.at(i) - tmp_t;
        int dist   = abs(x.at(i) - tmp_x) + abs(y.at(i) - tmp_y);
        if (((t_diff % 2) != (dist % 2)) || (t_diff < dist)) {
            cout << "No" << endl;
            exit(0);
        }
        tmp_t = t.at(i);
        tmp_x = x.at(i);
        tmp_y = y.at(i);
    }
    cout << "Yes" << endl;
}

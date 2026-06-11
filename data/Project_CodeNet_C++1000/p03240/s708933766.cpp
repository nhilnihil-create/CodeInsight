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
    vector<int> x(N);
    vector<int> y(N);
    vector<ll>  h(N);
    for (int i = 0; i < N; i++) {
        cin >> x.at(i) >> y.at(i) >> h.at(i);
    }
    FOR(Cx, 0, 101) {
        FOR(Cy, 0, 101) {
            FOR(i, 0, N) {
                if (h.at(i) > 0) {
                    int HH    = h.at(i) + abs(x.at(i) - Cx) + abs(y.at(i) - Cy);
                    int count = 0;
                    FOR(j, 0, N) {
                        if (h.at(j) ==
                            max(HH - abs(x.at(j) - Cx) - abs(y.at(j) - Cy),
                                0)) {
                            ++count;
                        }
                    }
                    if (count == N) {
                        cout << Cx << " " << Cy << " " << HH << endl;
                        exit(0);
                    }
                }
            }
        }
    }
}

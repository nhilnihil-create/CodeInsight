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
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
    }
    SORTR(a);
    int alice = 0;
    int bob   = 0;
    FOR(i, 0, N) {
        if (i % 2 == 0) {
            alice += a.at(i);
        } else {
            bob += a.at(i);
        }
    }
    cout << alice - bob << endl;
}

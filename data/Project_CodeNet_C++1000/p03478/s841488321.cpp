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
    int N, A, B;
    cin >> N >> A >> B;
    int ans = 0;
    FOR(i, 1, N + 1) {
        int n = i;
        int s = 0;
        while (n > 0) {
            s += n % 10;
            n /= 10;
        }
        if ((A <= s) & (s <= B)) { ans += i; }
    }
    cout << ans << endl;
}

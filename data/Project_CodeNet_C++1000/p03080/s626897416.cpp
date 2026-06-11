#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define REP(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define each(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define all(v) v.begin(), v.end()
#define mset(a, n) memset(a, n, sizeof(a))

typedef long long ll;

const int INF = 1000000000;
const int MOD = 1000000007;

int main(int argc, char *argv[]) {
    // cin.tie(0);
    // ios::sync_with_stdio(false);
    int N; cin >> N;
    string s; cin >> s;
    int r = 0;
    rep(i, N) if (s[i] == 'R') r++;
    cout << (r > N-r ? "Yes" : "No") << endl;
    return 0;
}
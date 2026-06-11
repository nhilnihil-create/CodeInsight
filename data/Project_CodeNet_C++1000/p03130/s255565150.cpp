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
    vector<int> town(4,0);
    rep(i, 3) {
        int a, b;
        cin >> a >> b;
        town[--a]++, town[--b]++;
    }
    bool flg = true;
    rep(i, 4) if (town[i] > 2) flg = false;
    cout << (flg ? "YES" : "NO") << endl;
    return 0;
}
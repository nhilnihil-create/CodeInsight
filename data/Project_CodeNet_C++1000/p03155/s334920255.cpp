#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define MOD 1e9+7;
#define INF (1 << 30)
#define REP(i,m,n) for(int i=(int)m; i < (int)n; ++i)
#define rep(i,n) REP(i,0,n)


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b; cin >> n >> a >> b;
    cout << (n-a+1)*(n-b+1) << '\n';
    return 0;
}
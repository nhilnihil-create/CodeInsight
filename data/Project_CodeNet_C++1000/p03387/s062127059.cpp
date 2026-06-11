#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

int a[3];

bool allsame() {
    bool ret = true;
    rep(i,2) if (a[i] != a[i+1]) ret = false;
    return ret;
}

int main() {
    rep(i,3) cin >> a[i];
    int ans = 0;
    while (!allsame()) {
        sort(a, a+3);
        a[0]++;
        sort(a, a+3);
        a[0]++;
        ans++;
    }
    cout << ans << endl;
}
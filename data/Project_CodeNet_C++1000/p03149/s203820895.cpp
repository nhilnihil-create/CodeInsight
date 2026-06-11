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

int main() {
    int a[4];
    rep(i,4) cin >> a[i];
    sort(a, a+4);
    int b[4] = {1, 4, 7, 9};
    string ans = "YES";
    rep(i,4) {
        if (a[i] != b[i]) ans = "NO";    
    }
    cout << ans << endl;
}
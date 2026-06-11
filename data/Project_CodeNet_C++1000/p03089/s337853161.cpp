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
    int n;
    cin >> n;
    vector<int> b(n);
    rep(i,n) cin >> b[i];
    vector<int> ans;
    while (b.size() > 0) {
        bool ok = false;
        for (int i = b.size() - 1; i >= 0; i--) {
            if (b[i] == i + 1) {
                ans.push_back(b[i]);
                b.erase(b.begin() + i);
                ok = true;       
                break;
            }
        }
        if (!ok) {
            cout << -1 << endl;
            return 0;
        }
    }
    reverse(ans.begin(), ans.end());
    rep(i,n) cout << ans[i] << endl;
}
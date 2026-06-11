#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

ll d[200010], t[200010];

int main(){
    int n;
    cin >> n;
    rep(i, n) cin >> d[i];
    int m;
    cin >> m;
    rep(i, m) cin >> t[i];

    if (m > n) {
        cout << "NO" << endl;
        return 0;
    }
    multiset<ll> ms;
    rep(i, n) ms.insert(d[i]);

    rep(i, m){
        auto it = ms.find(t[i]);
        if (it != ms.end()) {
            ms.erase(it);
        }
        else {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}

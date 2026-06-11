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


ll c[550], s[550], f[550];

int main(){
    int n;
    cin >> n;
    rep(i, n - 1) cin >> c[i] >> s[i] >> f[i];

    
    for (int k = 0; k < n; k++){
        ll now = 0;
        for(int i = k; i < n - 1; i++){
            ll p;
            if (now <= s[i]) p = 0;
            else p = (now - s[i] + f[i] - 1) / f[i];
            now = s[i] + p * f[i] + c[i];
        }
        cout << now << endl;
    }

    return 0;
}

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

int t[110], v[110], acc[110];
int b[50000];

int main(){
    int n;
    cin >> n;
    rep(i, n) cin >> t[i], t[i] *= 2;
    rep(i, n) cin >> v[i], v[i] *= 2;
    rep(i, n) acc[i+1] = acc[i] + t[i];

    int m = acc[n] + 1;

    rep(i, m) b[i] = min(i, acc[n] - i);

    rep(i, n){
        for(int j = 0; j < acc[i]; j++) b[j] = min(b[j], v[i] + acc[i] - j);
        for(int j = acc[i]; j < acc[i+1]; j++) b[j] = min(b[j], v[i]);
        for(int j = acc[i+1]; j < m; j++) b[j] = min(b[j], v[i] - acc[i+1] + j);
    }
    double ans = 0;
    rep(i, m) ans += b[i] + b[i+1];
    cout << fixed << setprecision(10) << ans/8.0 << endl;

    return 0;
}

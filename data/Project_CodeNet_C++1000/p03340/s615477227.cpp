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


ll a[200010];

int main(){
    int n;
    cin >> n;
    rep(i, n) cin >> a[i];
    ll res = 0;
    int right = 0;
    ll now = 0;
    for (int left = 0; left < n; ++left) {
        while (right < n && (now ^ a[right]) == (now + a[right])) {
            now += a[right];
            ++right;
        }
        res += (right - left);
        if (right == left) ++right;
        else now -= a[left];
    }

    cout << res << endl;

    return 0;
}

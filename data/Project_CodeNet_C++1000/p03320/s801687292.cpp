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

int digitSum(ll a){
    int res = 0;
    while(a > 0){
        res += a % 10;
        a /= 10;
    }
    return res;
}

int main(){
    ll k;
    cin >> k;

    int cnt = 0;
    ll ans = 1, base = 1;
    while(cnt < k){
        cout << ans << endl;
        ll tmp1 = ans + base;
        ll tmp2 = ans + 10 * base;
        if (tmp1 * digitSum(tmp2) <= tmp2 * digitSum(tmp1)) ans = tmp1;
        else ans = tmp2, base *= 10;
        cnt++;
    }

    return 0;
}

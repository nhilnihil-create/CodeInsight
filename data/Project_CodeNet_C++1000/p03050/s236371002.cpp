#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 998244353;

int main() {
    ll n, ans;
    cin >> n;

    ans = 0;
    for(ll i = 1; i * i <= n; i++){
        if((n - i) % i == 0){
            ll m = (n - i) / i;
            if(i < m){
                ans += m;
            }
        }
    }

    cout << ans << endl;
    return 0;
}

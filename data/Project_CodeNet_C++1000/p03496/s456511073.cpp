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


ll a[55];
int n;

void print1(ll mx){
    int idx;
    rep(i, n) if (a[i] == mx) idx = i + 1;
    rep(i, n) cout << idx << " " << i + 1 << endl;
    rep(i, n-1) cout << i + 1 << " " << i + 2 << endl;
}

void print2(ll mn){
    int idx;
    rep(i, n) if (a[i] == mn) idx = i + 1;
    rep(i, n) cout << idx << " " << i + 1 << endl;
    rrep(i, n-1) cout << i + 2 << " " << i + 1 << endl;
}

int main(){
    cin >> n;
    ll mx = -LINF, mn = LINF;
    rep(i, n) {
        cin >> a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }

    cout << 2 * n - 1 << endl;

    if (abs(mx) >= abs(mn)){
        print1(mx);
    }
    else if (abs(mn) > abs(mx)){
        print2(mn);
    }

    return 0;
}

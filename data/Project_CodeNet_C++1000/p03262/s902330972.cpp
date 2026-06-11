#include <bits/stdc++.h>
#define FOR(i, l, r) for(ll i = l; i < r; i++)
#define rep(i, N) FOR(i, 0, N)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<ll> vl;
const ll MOD = round(1e9+7);

ll gcd(ll a, ll b){
    if(a < b) swap(a, b);
    if(b <= 0) return -1;
    ll r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main() {
    int N,X; cin >> N >> X;
    vi x(N); rep(i,N) cin >> x[i];

    sort(x.begin(), x.end());
    int shift = min(x[0], X);
    X -= shift;
    rep(i,N) x[i] -= shift;
    int ans;
    if(x[N-1] != 0) {
        ans = x[N-1];
        if(X != 0) ans = gcd(ans, X);
        rep(i,N-1){
            if(x[i] != 0)
                ans = gcd(ans, x[i]);
        }
    }else{
        ans = X;
    }

    cout << ans;
    return 0;
}

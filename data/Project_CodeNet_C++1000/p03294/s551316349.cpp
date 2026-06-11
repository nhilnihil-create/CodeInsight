#include <bits/stdc++.h>
#define FOR(i, l, r) for(ll i = l; i < r; i++)
#define rep(i, N) FOR(i, 0, N)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<ll> vl;
const ll MOD = round(1e9+7);


int main() {
    int N; cin >> N;
    vi a(N); rep(i,N) cin >> a[i];
    ll ans = 0;
    rep(i,N) ans += a[i]-1;
    
    //printf("%.15lf", ans);
    cout << ans <<"\n";
    return 0;
}

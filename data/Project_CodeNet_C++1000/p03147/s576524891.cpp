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
    vi h(N); rep(i,N) cin >> h[i];

    int ans = -1;
    rep(i,100005){
        int l = N,r = N;
        rep(j,N) if(h[j] > 0) {l = j; break;}
        FOR(j,l,N) if(h[j] <= 0) {r = j; break;}
        if(l == N) {ans = i; break;}
        FOR(j,l,r) h[j]--;
    }

    cout << ans << endl;
    return 0;
}

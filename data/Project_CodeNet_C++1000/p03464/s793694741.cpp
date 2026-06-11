#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

ll ft(ll a, ll b) {
    return (a + ((a % b) ? (b - a % b) : 0)) / (b);
}

int main() {
    int K; cin >> K;
    ll A[K]; rep(i, K) cin >> A[i];
    ll L = 2, R = 3;
    bool ok = true;
    for(int i = K - 2; i >= 0; --i) {
        ll mult = ft(L, A[i]) * A[i];
        if(L <= mult && mult <= R) {
            L = mult;
            R = ll(R / A[i]) * A[i] + A[i] - 1;
        } else {
            ok = false;
            break;
        }
    }
    if(A[K - 1] != 2) ok = false;
    if(ok) cout << L << ' ' << R << endl;
    else cout << -1 << endl;
}

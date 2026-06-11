#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    ll N; ll M; cin >> N >> M;
    ll ans = 1;
    for(ll i = 1; i * i <= M; ++i) {
        if(M % i == 0) {
            if(M / i >= N)
                ans = max(ans, i);
            if(i >= N)
                ans = max(ans, M / i);
        }
    }
    cout << ans << endl;
}

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
    ll N, K; cin >> N >> K;
    ll cntK2 = 0, cnt0 = 0;
    for(int i = 1; i <= N; ++i) {
        if(i % K == K / 2) ++cntK2;
        if(i % K == 0) ++cnt0;
    }
    ll ans = ((K%2 == 0) ? cntK2 * cntK2 * cntK2 : 0) + cnt0 * cnt0 * cnt0;
    cout << ans << endl;
}

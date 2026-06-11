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
//#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    int N; cin >> N;
    ll A[N]; rep(i, N) cin >> A[i];
    ll ans = 0;
    bool ok = true;
    rep(i, N - 1) {
        if(1 < A[i + 1] - A[i]) {
            ok = false;
            break;
        }else if(A[i] < A[i + 1]) {
            ++ans;
        }else if(A[i] >= A[i + 1]) {
            ans += A[i + 1];
        }
    }
    if(A[0] != 0) ok = false;
    if(ok) cout << ans << endl;
    else cout << -1 << endl;
}

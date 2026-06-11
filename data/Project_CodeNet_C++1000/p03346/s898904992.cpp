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
    int P[N], cnt[N];
    rep(i, N) cin >> P[i], cnt[P[i] - 1] = i;
    int cnt1 = 1, ans = 1;
    rep(i, N - 1) {
        if(cnt[i] < cnt[i + 1]) {
            ++cnt1;
        }else {
            ans = max(ans, cnt1);
            cnt1 = 1;
        }
    }
    ans = max(ans, cnt1);
    cout << N - ans << endl;
}

#include <bits/stdc++.h>
#define REP0(i, n) for (ll i = 0; i < n; i++)
#define REP1(i, n) for (ll i = 1; i <= n; i++)
#define X first
#define Y second
#define pb push_back
#define ALL(arr) arr.begin(), arr.end()
#define MMST(arr, val) memset(arr, val, sizeof(arr))
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> llp;
const ll INF = 4e18;
const double PI = acos(-1);
ll n;
ll arr[100005];
ll cnt[200005];
bool check(ll k) {
    ll now = 0;
    ll pls = 0;
    ll ans = 0;
    MMST(cnt, 0);
    cnt[100000] = 1;
    REP1(i, n) {
        if (arr[i] <= k) {
            now++;
            pls += cnt[100000+now-1];
            ans += pls;
            cnt[100000+now]++;
        }
        else {
            now--;
            pls -= cnt[100000+now];
            ans += pls;
            cnt[100000+now]++;
        }
//        cout << pls << '\n';
    }
//    cout << k << ' ' << ans << '\n';
    return ans * 2 - 1 >= n * (n+1) / 2;
}
int main() {
    IOS;
    cin >> n;
    REP1(i, n) {
        cin >> arr[i];
    }
    ll bot = 0, top = 1000000005, mid;
    while (top > bot+1) {
        mid = (top + bot) / 2;
        if (check(mid)) {
            top = mid;
        }
        else {
            bot = mid;
        }
    }
    cout << top << '\n';
    return 0;
}
/*
4 5 1
1 2 20
1 4 10
2 3 5
2 4 6
3 4 5
2 7
*/

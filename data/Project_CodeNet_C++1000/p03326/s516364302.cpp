#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<iomanip>
#include<map>
#include<cstring>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const ll LLINF = 4 * 1e18;
/* -- template -- */

struct cake{
    ll bea, del, fav;
};

int main() {
    int N, M; cin >> N >> M;
    cake x[N];
    rep(i, N) cin >> x[i].bea >> x[i].del >> x[i].fav;
    ll ans = 0;
    for(int bit = 0;bit < 8;++bit) {
        ll a[3];
        for(int i = 0; i < 3; ++i){
            if(1 << i & bit){
                a[i] = 1;
            }else{
                a[i] = -1;
            }
        }
        ll temp[N];
        rep(j, N) {
            temp[j] = a[0] * x[j].bea + a[1] * x[j].del + a[2] * x[j].fav;
        }
        sort(temp, temp + N, greater<ll>());
        ll tempans = 0;
        rep(j, M)tempans += temp[j];

        ans = max(tempans, ans);
    }

    cout << ans << endl;
}

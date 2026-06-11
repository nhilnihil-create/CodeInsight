#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    ll d, g;
    cin >> d >> g;
    vector<ll> p(d);
    vector<ll> c(d);
    rep(i, d) {
        cin >> p[i] >> c[i];
    }
    ll ans = 1e18;
    //cout << (1<<d) << endl;
    rep(i, 1<<d) {
        ll sum = 0;
        ll cnt = 0;
        rep(j, d) {
            if ((i>>j) & 1) {
                sum += p[j] * 100 * (j+1) + c[j]; 
                cnt += p[j];
            }
        }
        //cout << i << " " << sum << " " << cnt << endl;
        bool over = false;
        for (int j = d-1; j >= 0; --j) {
            if ((i>>j) & 1) continue;
            int tmp_cnt = 0;
            while(1) {
                if (sum >= g) {
                    over = true;
                    break;
                }
                if (tmp_cnt == p[j]) break;
                sum += 100 * (j+1);
                ++tmp_cnt;
                ++cnt;
                //cout << tmp_cnt << " " << p[j] << endl;
            }
            if (over) break;
        }
        ans = min(ans, cnt);
        //cout << ans << " " << cnt << endl;
    }
    cout << ans << endl;
    return 0;
}

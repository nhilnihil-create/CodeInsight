#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

const ll inf = 1LL << 62;

template<class T> inline void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}
template<class T> inline void chmax(T& a, T b) {
    if (a < b) {
        a = b;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;
    vector<ll> x(N), y(N);
    Rep (i, N) {
        cin >> x[i] >> y[i];
    }

    ll ans = inf;
    Rep (i, N) {
        ll left = x[i];
        Rep (j, N) {
            ll right = x[j];
            Rep (k, N) {
                ll up = y[k];
                Rep (l, N) {
                    ll down = y[l];
                    ll cnt = 0;
                    Rep (m, N) {
                        if (left <= x[m] && x[m] <= right && down <= y[m] && y[m] <= up) cnt++;
                    }
                    if (cnt >= K) chmin(ans, (right - left) * (up - down));
                }
            }
        }
    }

    cout << ans << endl;
}
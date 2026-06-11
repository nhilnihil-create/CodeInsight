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
#include<bitset>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    Rep (i, N) {
        cin >> a[i];
    }
    vector<ll> all;
    Rep (i, N) {
        ll now = 0;
        for (ll j = i; j < N; j++) {
            now += a[j];
            all.push_back(now);
        }
    }

    // cout << all.size() << endl;

    vector<bool> use(N*(N+1)/2, true), tmp(N*(N+1)/2, true);
    ll ans = 0;
    ll s = all.size();
    for (ll i = 50; i >= 0; i--) {
        // cout << "i=" << i << endl;
        Rep (j, s) tmp[j] = true;
        ll cnt = 0;
        Rep (j, s) {
            if ((all[j] & ((ll)1 << i)) && use[j]) {
                cnt++;
                // cout << all[j] << endl;
            } else {
                tmp[j] = false;
            }
        }

        // cout << i << " " << cnt << endl;
        if (cnt >= K) {
            ans += (ll)1 << i;
            Rep (j, s) {
                use[j] = tmp[j];
            }
        }
    }

    cout << ans << endl;

    
}
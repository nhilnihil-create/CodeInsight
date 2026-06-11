#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef uint64_t ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();


int main() {
    int n, val, k;
    cin >> n >> k;
    ll acc = 0;

    vector<ll> dp = {0};
    for(int i = 0; i < n; i++) {
        cin >> val;
        acc += val;
        dp.push_back(acc);
    }
    map<ll, int> cnt;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cnt[dp[i+1]-dp[j]] += 1;
        }
    }


    ll mx = cnt.rbegin()->first;
    int nbit = 0;
    while ((1LL<<nbit) < mx) {
        nbit += 1;
    }
    // cout << mx << endl;
    // cout << nbit << endl;
    ll ans = 0;
    for(int b = nbit; b >= 0; b--) {
        auto it = cnt.rbegin();
        acc = 0;
        map<ll, int> cnt3;
        for(; it != cnt.rend(); ++it) {
            if ((it->first >> b)&1) {
                acc += it->second;
                cnt3[it->first&((1ll<<b)-1)] += it->second;
            } else {
                break;
            }
        }
        if (acc >= k) {
            ans += (1ll << b);
        } else {
            for(; it != cnt.rend(); ++it) {
                cnt3[it->first&((1ll<<b)-1)] += it->second;
            }
        }
        cnt.swap(cnt3);
    }
    cout << ans << endl;
    return 0;
}


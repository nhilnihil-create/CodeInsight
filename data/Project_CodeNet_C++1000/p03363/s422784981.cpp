//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    int n;
    cin >> n;
    vi a(n);
    vi sum(n+1);
    rep(i, n) {
        cin >> a[i];
        sum[i+1] = sum[i] + a[i];
    }

    sort(sum.begin(), sum.end());
    ll ans = 0LL;
    map<ll, int> mp;
    rep(i, n+1) {
        mp[sum[i]]++;
    }

    for(pair<ll, int> x:mp) {
        if(x.second&1) {
            ans += (x.second-1)/2*(ll)x.second;
        } else {
            ans += x.second/2*((ll)x.second-1);
        }
        
    }

    cout << ans << endl; 
}
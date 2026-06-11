#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<P> v;
    rep(i,n){
        int t;
        ll d;
        cin >> t >> d;
        v.emplace_back(d, t-1);
    }
    sort(v.begin(), v.end(), greater<>());
    ll sum = 0, type = 0;
    vector<int> cnt(n, 0);
    rep(i,k){
        sum += v[i].first;
        if(cnt[v[i].second]++ == 0) ++type;
    }
    ll ans = sum + type * type;
    for(int i = k, j = k-1; i < n; ++i){
        if(cnt[v[i].second] > 0) continue;
        ++cnt[v[i].second];
        sum += v[i].first;
        ++type;
        while(j >= 0){
            if(cnt[v[j].second] > 1){
                --cnt[v[j].second];
                sum -= v[j].first;
                chmax(ans, sum + type * type);
                --j;
                break;
            }
            --j;
        }
        if(j < 0) break;
    }
    cout << ans << endl;
    return 0;
}

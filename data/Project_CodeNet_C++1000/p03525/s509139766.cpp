#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main() {
    ll n, m, i, j, k;
    cin >> n;
    vector<ll> d(n);
    for(i = 0; i < n; i++) {
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    if(n >= 24 || d[0] == 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<ll> cnt(12, 0),tim(24,0);
    tim[0]=1;
    for(i = 0; i < n; i++) {
        cnt[d[i]]++;
        if(cnt[d[i]] > 2) {
            cout << 0 << endl;
            return 0;
        }
    }
    if(cnt[12] > 1) {
        cout << 0 << endl;
        return 0;
    }
    vector<ll> solo;
    for(i=1;i<=12;i++){
        if(cnt[i]==2){
            tim[i] = 1;
            tim[24-i]=1;
        }else if(cnt[i]==1){
            solo.push_back(i);
        }
    }
    vector<ll> t(n, 0);
    ll ret = 0;
    for(i = 0; i < 1 << solo.size(); i++) {
        t = tim;
        for(j = 0; j < solo.size(); j++) {
            if((i >> j) & 1) {
                t[solo[j]] = 1;
            } else {
                t[24-solo[j]] = 1;
            }
        }
        ll now = INF, cur = 0;
        for(j = 1; j < 24; j++) {
            if(t[j] == 1){
                now = min(now, abs(cur - j));
                cur = j;
            }
        }
        now = min(now,min(cur,24-cur));
        ret = max(ret, now);
    }
    cout << ret << endl;
    return 0;
}
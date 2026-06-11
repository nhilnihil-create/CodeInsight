#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N, K;
    cin >> N >> K;
    vector<bool> use(N+1, false);
    vector<pair<int, int>> sushi(N);
    for (int i = 0; i < N; i++){
        ll t, d;
        cin >> t >> d;
        sushi[i] = {t, d};
    }
    sort(sushi.begin(), sushi.end(), [](pair<ll, ll> l, pair<ll, ll> r){
        return l.second > r.second;});
    ll kinds = 0;
    ll ans = 0;
    ll val = 0;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    for (int i = 0; i < K; i++) {
        ll t = sushi[i].first;
        ll d = sushi[i].second;
        val += d;
        if (use[t]) q.push(d);
        else {
            use[t] = true;
            kinds++;
        }
    }
    ans = kinds*kinds + val;
    int pos = K;
    while (kinds < K && pos < N) {
        ll t = sushi[pos].first;
        ll d = sushi[pos].second;
        if (!use[t]){
            use[t] = true;
            val = val + d - q.top();
            q.pop();
            kinds++;
            ans = max(ans, kinds*kinds + val);
        }
        pos++;
    }
    cout << ans << endl;
}
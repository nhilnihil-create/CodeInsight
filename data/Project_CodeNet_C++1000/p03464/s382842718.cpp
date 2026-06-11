#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main() {
    ll n, m, i, j, k;
    cin >> k;
    vector<ll> a(k);
    for(i = 0; i < k; i++) {
        cin >> a[i];
    }
    ll down = 2, up = 2;
    reverse(a.begin(), a.end());
    for(ll x : a) {
        ll now_d, now_u;
        now_d = down / x;
        if(down % x != 0) {
            now_d++;
        }
        // 現時点のnow_d := 作られたグループの最小
        now_d *= x;
        if(now_d > up) {
            cout << -1 << endl;
            return 0;
        }
        now_u = up/x;
        now_u= (now_u+1)*x-1;
        down = now_d;
        up = now_u;
        //cout << down << " " << up << endl;
    }
    cout << down << " " << up << endl;
    return 0;
}
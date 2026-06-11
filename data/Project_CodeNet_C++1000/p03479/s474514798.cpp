#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main() {
    ll x, y; cin >> x >> y;

    ll ans = 1;
    for(ll i = x; i <= y / 2; i*=2) {
        ll tmp = i, cnt = 1;
        while(1){
            tmp *= 2;
            if(y < tmp) break;
            cnt++;
        }
        if(cnt < ans) break;
        else ans = cnt;
    }
    cout << ans << endl;
}


#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    vector<ll> w(n + 1, 0);
    vector<ll> e(n + 1, 0);
    if(s[0] == 'W') w[0]++;
    else s[0]++;
    for(int i = 0; i < n; i++){
        if(s[i] == 'W'){
            w[i + 1] = w[i] + 1;
            e[i + 1] = e[i];
        }else{
            e[i + 1] = e[i] + 1;
            w[i + 1] = w[i];
        }
    }
    ll ans = 1LL << 60;
    for(int i = 0; i < n; i++){
        ll l = 0, r = 0;
        if(i > 0) l = w[i] - w[0];
        if(i < n - 1) r = e[n] - e[i + 1];
        ans = min(ans, l + r);
    }
    cout << ans << endl;
}

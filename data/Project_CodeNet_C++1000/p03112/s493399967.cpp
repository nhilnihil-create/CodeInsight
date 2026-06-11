#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int a, b, q;
vector<ll> s, t;

ll mindis(ll x, int i, int j){
    ll res = 3e10;
    res = min(res, max(s[i] - x, t[j] - x));
    res = min(res, max(x - s[i - 1], x - t[j - 1]));
    res = min(res, 2 * min(x - t[j - 1], t[j] - x) + min(x - s[i - 1], s[i] - x));
    res = min(res, min(x - t[j - 1], t[j] - x) + 2 * min(x - s[i - 1], s[i] - x));
    return res;
}

int main(){
    cin >> a >> b >> q;
    s.resize(a + 2);
    t.resize(b + 2);
    s[0] = -2e10;
    s[a + 1] = 3e10;
    t[0] = -2e10;
    t[b + 1] = 3e10;

    rep(i, a) cin >> s[i + 1];
    rep(i, b) cin >> t[i + 1];

    rep(num, q){
        ll x;
        cin >> x;
        int i = lower_bound(s.begin(), s.end(), x) - s.begin();
        int j = lower_bound(t.begin(), t.end(), x) - t.begin();
        cout << mindis(x, i, j) << endl;
    }
}

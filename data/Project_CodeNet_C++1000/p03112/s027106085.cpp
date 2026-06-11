#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll searchx(const vector<ll>& s, const vector<ll>& t, ll x);
ll searchst(const vector<ll>& s, ll x);

int main() {
    ll a, b, q;
    cin >> a >> b >> q;
    vector<ll> s(a);
    vector<ll> t(b);
    for (ll i = 0;i < a;++i)cin >> s[i];
    for (ll i = 0;i < b;++i)cin >> t[i];
    for (ll i = 0;i < q;++i) {
        ll x;
        cin >> x;
        ll ans = searchx(s, t, x);
        ans = min(ans, searchx(t, s, x));
        cout << ans << endl;
    }
}

//xから始めて、先にsを訪れてそのあとtを訪れる時の最小値
ll searchx(const vector<ll>& s, const vector<ll>& t, ll x) {
    auto it = lower_bound(s.begin(), s.end(), x);
    if (it == s.end()) {
        return abs(x - s.back()) + searchst(t, s.back());
    }
    else if (it == s.begin()) {
        return abs(x - s.front()) + searchst(t, s.front());
    }
    else {
        ll ret = abs(x - *it) + searchst(t, *it);
        ret = min(ret, abs(x - *(it - 1)) + searchst(t, *(it - 1)));
        return ret;
    }
}

//xからsを訪れる最小値
ll searchst(const vector<ll>& s, ll x) {
    auto it = lower_bound(s.begin(), s.end(), x);
    if (it == s.end()) {
        return abs(x - s.back());
    }
    else if (it == s.begin()) {
        return abs(x - s.front());
    }
    else {
        return min(abs(x - *it), abs(x - *(it - 1)));
    }
}
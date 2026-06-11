#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (long long (i)=(0);(i)<(long long)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;

template<class T> void vin(vector<T>& v, int n) {
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
}

int S(ll n) {
    string s = to_string(n);
    int res = 0;
    rep(i, s.size()) res += s[i]-'0';
    return res;
}

ll f(ll n) {
    string s = to_string(n);
    ll sn = S(n);
    double mn = 1e18;
    ll next = -1;
    rep(i, s.size()) {
        rep(d, 10) {
            string t = s;
            t[i] = d + '0';
            for (int j=i+1; j<s.size(); ++j) t[j] = '9';
            ll m = stoll(t);
            if (m < n) continue;
            ll sm = S(m);
            if (mn > (double)m/sm) {
                mn = (double)m/sm;
                next = m;
            }
        }
    }
    return next;
}

int main() {
    ll K;
    cin >> K;
    ll a = 1;
    rep(i, K) {
        cout << a << endl;
        a = f(a+1);
    }
}

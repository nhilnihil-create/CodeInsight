#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

ll a, b, c, d;

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

bool solve() {
    if(a < b) return false; // 最初に買えないので
    if(d < b) return false; // 追加が追いつかないゆえ
    if(c >= b - 1) return true;

    ll g = gcd(b, d);
    // できる整数は D*p - B*q + A -> A + g*x -> g で割って A%g 余る.
    // g で割って a%g あまる数で、c より大きく b 未満な整数を知りたい
    // g で割って a%g 余る数の b 未満の最大の数. A + (Gの倍数)
    ll Max = (b - a % g + g - 1) / g * g + a % g - g;
    Max = b + a % g - g;
    if(Max > c)
        return false;
    else
        return true;
}

int main() {
    ll n, m, i, j, k;
    ll T;
    cin >> T;
    for(ll t = 0; t < T; t++) {
        set<ll> st;
        st.insert(a);
        cin >> a >> b >> c >> d;
        if(solve())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
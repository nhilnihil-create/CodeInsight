#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;


int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N,0);
    map<ll,ll> mp;

    rep(i, N){
        ll x;
        cin >> x;
        mp[x]++;
    }

    rep(i, M){
        ll num1, num2;
        cin >> num1 >> num2;
        mp[num2] += num1;
    }

    ll ans = 0;
    ll c = N;
    for (auto p = mp.rbegin(); p != mp.rend(); ++p)
    {
        pair<ll, ll> q = *p;
        ans += q.first * min(c, q.second);
        c -= q.second;
        if (c <= 0)
            break;
    }

    cout << ans << endl;
}
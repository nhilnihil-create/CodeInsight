#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf 2e9
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
using Graph = vector<vector<pair<ll, ll>>>;

bool is_prime(ll num) {
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false;

    for (ll i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int main()
{
    ll N; cin >> N;
    vll v{11}; ll i = 16;
    while (v.size() < N) {
        if (is_prime(i)) v.push_back(i);
        i+=5;
    }
    rep(i, N) cout << v[i] << " ";
    cout << endl;
    return 0;
}
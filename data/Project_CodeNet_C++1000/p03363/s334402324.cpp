#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll COM(ll a, ll b) {
    ll x = 1;
    ll y = 1;
    ll cnt = b;
    for (int i = 0; i < cnt; i++) {
        x *= a;
        y *= b;
        a--;
        b--;
    }
    return x/y;
}

int main() {
    ll N;
    ll ans = 0;
    cin >> N;
    vector<ll>A(N);
    set<ll>S;
    map<ll, ll>mp;
    mp[0]++;
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
        S.insert(sum);
        mp[sum]++;
    }
    for (auto itr = S.begin(); itr != S.end(); itr++) {
        ans += COM(mp[*itr], 2);
    }
    cout << ans << endl;
}

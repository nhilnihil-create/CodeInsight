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


int main()
{
    ll N, M; cin >> N >> M;
    vll A(N);
    rep(i, N) {
        cin >> A[i];
    }
    vll sum(N);
    ll k = 0; 
    rep(i, N) {
        if (i == 0) sum[i] = A[i]; else sum[i] = A[i] + sum[i-1];
    }
    sum.insert(sum.begin(), 0);
    //for (auto elem : sum) cout << elem << " "; cout << endl;
    map<ll, ll> mp;
    rep(i, sum.size()) {
        mp[sum[i] % M]++;
    }

    ll cnt = 0;
    for (auto p : mp) {
        cnt += p.second * (p.second - 1) / 2;
    }
    //for (ll i = 0; i < N; i++) {
    //    for (ll j = i + 1; j < N + 1; j++) {
    //        if ((sum[j] - sum[i]) % M == 0) cout << i << " " << j << " " << sum[j] - sum[i] << endl;
    //    }
    //}
    cout << cnt << endl;

    return 0;
}
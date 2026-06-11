#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> buy(n);
    vector<ll> a(n), b(n);
    rep(i, n) {
        cin >> a[i] >> b[i];
    }
    rep(i, n) {
        buy[i].first = a[i];
        buy[i].second = b[i];
    }
    sort(all(buy));
    ll sum = 0;
    rep(i, n) {
        if(m <= 0) break;
        ll M = min(buy[i].second, m);
        sum += buy[i].first * M;
        m -= M;
    }
    cout << sum << endl;

    return 0;
}
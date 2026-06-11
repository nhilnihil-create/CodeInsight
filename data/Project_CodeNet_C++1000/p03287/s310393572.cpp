//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    ll sum = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    rep(i, n) {
        int a;
        cin >> a;
        sum += a;
        sum %= m;
        mp[sum]++;
    }

    ll ans = 0;
    for(P x:mp) {
        ans += (ll)x.second * (x.second-1) / 2;
    }

    cout << ans << endl;
}
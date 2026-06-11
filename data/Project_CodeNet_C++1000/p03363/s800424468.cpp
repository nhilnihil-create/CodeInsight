#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
const ll mod = 1e9 + 7;
int main()
{
    // AGC023-A, 1028, 
    int n; cin >> n;
    vector<ll> a(n), sum(n);
    rep(i, n) {
        cin >> a[i];
        if (i == 0) sum[i] = a[i];
        else sum[i] = sum[i - 1] + a[i];
    }
    map<ll, int> mp;
    rep(i, n) mp[sum[i]]++;
    ll ans = 0;
    for (auto a : mp) {
        ll num = a.second;
        ans += (num * (num - ll(1))) / ll(2);
        if (a.first == 0) ans += num;
    }
    cout << ans << endl;

    return 0;
}
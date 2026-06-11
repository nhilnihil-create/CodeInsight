#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Rep(i, k, n) for (int i = k; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
long long dp[100010];
long long h[100010];
const int MOD = 1000000007;

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<ll> s(n + 1, 0);
    map<ll, ll> nums;
    rep(i, n) s[i + 1] = s[i] + a[i];
    rep(i, n + 1) nums[s[i]]++;

    ll res = 0;
    for (auto it : nums)
    {
        ll num = it.second;
        res += num * (num - 1) / 2;
    }
    cout << res << endl;
}
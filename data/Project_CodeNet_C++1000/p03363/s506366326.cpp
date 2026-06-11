#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    int n;
    ll a;
    cin >> n;
    vector<ll> cnt(n, 0);
    vector<ll> asum(n + 1, 0);
    rep(i, n)
    {
        cin >> a;
        cnt[i] = a;
    }
    rep(i, n) asum[i + 1] = asum[i] + cnt[i];
    map<ll, ll> lap;
    rep(i, n + 1) lap[asum[i]]++;
    ll out = 0;
    for (auto it : lap)
    {
        out += it.second * (it.second - 1) / 2;
    }
    cout << out << endl;
    return 0;
}
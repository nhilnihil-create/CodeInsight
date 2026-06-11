// https://atcoder.jp/contests/abc085/tasks/abc085_d
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <bitset>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define REP(i, n) for(size_t i = 0; i < (n); ++i)

int main()
{
    int N;
    ll H;
    cin >> N >> H;
    vector<ll> a(N), b(N);
    ll amax = -1;
    REP(i, N)
    {
        cin >> a[i] >> b[i];
        amax = std::max(amax, a[i]);
    }
    sort(b.begin(), b.end(), std::greater<ll>());
    ll ans = 0;
    REP(i, N)
    {
        if (amax > b[i]) break;
        H -= b[i];
        ++ans;
        if (H <= 0) break;
    }
    if (H > 0)
    {
        ll cnt = (H + amax - 1) / amax;
        ans += cnt;
    }
    cout << ans << endl;
    return 0;
}

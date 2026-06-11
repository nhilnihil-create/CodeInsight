#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
typedef pair<int, int> P;

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

int main()
{
    int N, M;
    cin >> N >> M;
    map<ll, int> Amap;
    vector<pair<ll, int>> cnt;

    rep(i, N)
    {
        ll a;
        cin >> a;
        Amap[a]++;
    }
    for (auto p : Amap) {
        cnt.push_back(make_pair(p.first, p.second));
    }
    rep(i, M)
    {
        ll b;
        int c;
        cin >> b >> c;
        cnt.push_back(make_pair(c, b));
    }
    sort(cnt.rbegin(), cnt.rend());
    int num = 0;
    ll ans = 0;
    for (int i = 0; i < cnt.size(); i++) {
        ans += cnt[i].first * cnt[i].second;
        num += cnt[i].second;
        if (num >= N) {
            ans -= cnt[i].first * (num - N);
            break;
        }
    }
    cout << ans << endl;

    return 0;
}
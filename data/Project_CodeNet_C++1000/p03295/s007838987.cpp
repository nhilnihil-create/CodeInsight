#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;
using Graph = vector<vector<ll>>;

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> BA; //sortのためBが先
    rep(i, m)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        BA.emplace_back(b, a);
    }
    sort(BA.begin(), BA.end());

    ll now = -1;
    ll ans = 0;
    rep(i, m)
    {
        ll b = BA[i].first;
        ll a = BA[i].second;
        if (now <a)
        {
            ans++;
            now = b-1;
        }
    }

    cout << ans << endl;
}
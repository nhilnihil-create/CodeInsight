#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n-1; i > 0; i--)
#define FOR(i, n, m) for(int i = n; i < (int)(m); i++)
#define PRINT(x) cout << x << endl
#define ALL(v) v.begin(), v.end()
#define INF (ll)1e18
#define PI 3.14159265358979

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll MOD = 1000000007;

int main()
{
    ll N, K;
    cin >> N >> K;

    vector<ll> a(N);
    REP(i, N) cin >> a[i];
    vector<ll> s(N);
    s[0] = a[0];
    REP(i, N-1) s[i+1] = s[i] + a[i+1];
    vector<ll> v;
    REP(i, N) {
        FOR(j, i, N) {
            if (i == 0) v.push_back(s[j]);
            else v.push_back(s[j] - s[i-1]);
        }
    }
    ll t = 45;
    ll ans = 0;
    REP(i, t) {
        ll n = 0;
        vector<ll> tmp;
        REP(j, v.size()) {
            if (v[j] & (1LL << (t-1-i))) {
                n++;
                tmp.push_back(v[j]);
            }
        }
        if (n >= K) {
            ans += (1LL << (t-1-i));
            v.clear();
            v.resize(tmp.size());
            REP(j, tmp.size()) v[j] = tmp[j];
        }
    }
    PRINT(ans);
    return 0;
}

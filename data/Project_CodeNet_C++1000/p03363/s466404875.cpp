#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
#define INF 10e12
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define max(x) *max_element(all(x))
#define min(x) *min_element(all(x))

using namespace std;

ll fac[MAX], finv[MAX], inv[MAX];

//二項係数の計算
void comint()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; ++i)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
ll com(ll n, ll k)
{
    if (n > k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//Nが素数か判定する
bool is_prime(ll N)
{
    for (ll i = 2; i * i <= N; ++i)
    {
        if (N % i == 0)
            return false;
    }
    return true;
}

//Nを素因数分解した結果のリストを返す
vector<ll> soinsubunkai(long long N)
{
    vector<ll> tmp;
    ll num = N;
    for (ll i = 2; i * i <= N; ++i)
    {
        if (N % i == 0)
        {
            ll j = N / i;
            if (is_prime(i))
            {
                while (num % i == 0)
                {
                    tmp.push_back(i);
                    num /= i;
                }
            }
            if (is_prime(j))
            {
                while (num % j == 0)
                {
                    tmp.push_back(j);
                    num /= j;
                }
            }
        }
    }
    return tmp;
}

//法mにおけるaの逆元を返す
ll modinv(ll a, ll m)
{
    ll b = m, u = 1, v = 0;
    while (b)
    {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0)
        u += m;
    return u;
}

//法mにおけるa^bの値を返す
ll modpow(ll a, ll n, ll m)
{
    ll res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll ans = 0;
    cin >> N;
    vector<ll> vec(N);
    rep(i, N) cin >> vec[i];
    vector<ll> ruisekiwa(N + 1);
    set<ll> st;
    ruisekiwa[0] = 0;
    rep(i, N)
    {
        ruisekiwa[i + 1] = ruisekiwa[i] + vec[i];
    }
    sort(all(ruisekiwa));
    map<ll, ll> mp;
    for (auto i : ruisekiwa)
        mp[i]++;

    for (auto i : mp)
    {
        ans += i.second * (i.second - 1) / 2;
    }

    cout << ans << endl;
}

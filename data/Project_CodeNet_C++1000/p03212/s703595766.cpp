#include <bits/stdc++.h>
#include <string>
//#define local
#ifdef local
#include "dbg-macro/dbg.h"
#endif
#define ll long long
#define pi (acos(-1))
#define rep(i, n) for (unsigned long long i = 0; i < (unsigned long long)(n); ++i)
using namespace std;
std::vector<unsigned ll> genprimevec(const unsigned ll N);


vector<ll>vec;ll n;
void f(ll x)
{
    if (x > n) { return; }
    vec.push_back(x);
    f((10 * x) + 3);
    f((10 * x) + 5);
    f((10 * x) + 7);
}
int main()
{
    cin >> n;
    ll ans = 0;
f(0);
    for (auto k : vec)
    {
        bool san = false, go = false, nana = false;
        std::string s = to_string(k);
        for (auto ch : s)
        {
            if (ch == '3') { san = true; }
            if (ch == '7') { nana = true; }
            if (ch == '5') { go = true; }
        }
	if(san&&go&&nana){
++ans;
	}
    }
    cout<<ans<<endl;
    return 0;
}
// https://atcoder.jp/contests/abc167/submissions/13086283
/*author  https://qiita.com/drken/items/0c88a37eec520f82b788*/
ll extgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}


std::vector<unsigned ll> genprimevec(const unsigned ll N)
{
    std::vector<bool> is_prime(N + 1);
    for (unsigned ll i = 0; i <= N; i++) { is_prime[i] = true; }
    std::vector<unsigned ll> P;
    for (unsigned ll i = 2; i <= N; i++)
    {
        if (is_prime[i])
        {
            for (unsigned ll j = 2 * i; j <= N; j += i) { is_prime[j] = false; }
            P.emplace_back(i);
        }
    }
    return P;
}

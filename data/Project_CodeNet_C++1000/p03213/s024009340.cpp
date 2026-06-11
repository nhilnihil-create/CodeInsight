#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define inf LLONG_MAX
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

map<ll, ll> primes;

void primefactorize(ll n)
{
    while (n % 2 == 0)
    {
        n /= 2;
        primes[2]++;
    }

    for (int i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            n /= i;
            primes[i]++;
        }
    }
    if (n > 2)
        primes[n]++;
}

int main()
{
    ll N;
    cin >> N;
    if (N == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 2; i <= N; i++)
    {
        primefactorize(i);
    }
    /*
    for (auto elem : primes) {
        cout << elem.first << " " << elem.second << endl;
    }
    */

    ll o3 = 0, o5 = 0, o15 = 0, o25 = 0, o75 = 0;
    for (auto elem : primes)
    {
        if (elem.second + 1 >= 75)
        {
            o75++;
        }
        if (elem.second + 1 >= 25)
        {
            o25++;
        }
        if (elem.second + 1 >= 15)
        {
            o15++;
        }
        if (elem.second + 1 >= 5)
        {
            o5++;
        }
        if (elem.second + 1 >= 3)
        {
            o3++;
        }
    }
    //cout << o3 << " " << o5 << " " << o25 << endl;

    ll ans = 0;
    ans += o75;
    ans += o25 * (o3 - 1);
    ans += o15 * (o5 - 1);
    ans += (o5 * (o5 - 1) / 2) * (o3 - 2);
    cout << ans << endl;
    return 0;
}
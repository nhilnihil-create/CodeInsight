#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll , ll> PLL;
typedef long double ld;

#define pb push_back
#define all(c) c.begin(),c.end()
#define allr(c) c.rbegin(),c.rend()
#define mod 1000000007
#define PI 3.14159265
#define endl '\n'
#define MAX

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, p;
    cin >> n >> p;
    map <ll, ll> mp;
    for (ll i = 2; i * i <= p; i++) {
        ll c = 0;
        if (p % i == 0) {
            while (p % i == 0) {
                p /= i;
                c++;
            }
            mp[i] += c;
        }
    }
    if (p) {
        mp[p] = 1;
    }
    ll ans = 1;
    for (auto it : mp) {
        ll a = it.first;
        ll b = it.second;
        ll d = b / n;
        ans *= pow(a, d);
    }
    cout << ans << endl;

    return 0;
}

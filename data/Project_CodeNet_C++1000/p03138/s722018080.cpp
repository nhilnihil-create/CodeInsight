#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

#define mt make_tuple
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sqr(x) ((ll)(x) * (x))

int main()
{
    ll n, k;
    cin >> n >> k;

    ll resenje = 0;

    vector<ll> v(n);

    for(auto &z : v)
        cin >> z;

    for(int i = 40; i >= 0; --i)
    {
        int brojac = 0;

        for(int j = 0; j < n; ++j)
        {
            //cout << (1LL<<i) << '\n';
            if((v[j]&(1LL<<i)))
            {
                ++brojac;
            }
        }

        if(brojac * 2 < n && (resenje + (1LL<<i) <= k))
        {
            resenje += (1LL<<i);
        }
    }

    ll suma = 0;

    //cout << resenje << '\n';

    for(int i = 0; i < n; ++i)
    {
        suma += (resenje^v[i]);
    }

    cout << suma << '\n';

    return 0;
}

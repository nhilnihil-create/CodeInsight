#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define scl(n) scanf("%lld", &n)
#define pcl(n) printf("%lld\n", n)
#define pcl1(n) printf("%lld ", n)
#define nln printf("\n")
#define dev(x) cout << #x << " " << x << " ";
#define PTT pair<ll, ll>

map<ll, ll> mp, mp1;
map<ll, ll>::iterator itr;

int main()
{
    ll t, n, x, a, b;
    scl(a);
    scl(b);
    ll i = 1, j = 0, k = 0;

    while (i <= 9)
    {
        j = 0;
        while (j <= 9)
        {
            k = 0;
            while (k <= 9)
            {
                ll num = 0;
                num += (i * 10000);
                num += i;
                num += (j * 1000);
                num += (j * 10);
                num += (k * 100);
                mp[num] += 1;
                k++;
            }
            j++;
        }
        i++;
    }
    ll cnt = 0;
    for (auto k : mp)
    {
        if (k.first >= a && k.first <= b)
        {
            cnt++;
        }
    }
    pcl(cnt);
    return 0;
}
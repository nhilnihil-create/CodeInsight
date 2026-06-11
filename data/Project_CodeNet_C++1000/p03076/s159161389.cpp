#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#include <bitset>
#define M 1000000007
#define M1 998244353

#define tr(container, it) \
for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

ll power(ll x, ll n)
{
    ll result = 1;
    while (n)
    {
        if (n % 2 == 1)
            result = result * x;
        n = n / 2;
        x = x * x;
    }
    return result;
}

ll gcd(ll a, ll b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

inline ll mul(ll x, ll y, ll m)
{
    ll z = 1LL * x * y;
    if (z >= m)
    {
        z %= m;
    }
    return z;
}

ll powmod(ll x, ll y, ll m)
{
    ll r = 1;
    while (y)
    {
        if (y & 1)
        {
            r = mul(r, x, m);
        }
        y >>= 1;
        x = mul(x, x, m);
    }
    return r;
}



void start()
{
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
/***********************************************************************************************************/

int main()
{
    start();
    int n=5;
    int a[n];
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int b=-1, c=0;

    for (int i=0;i<n;i++)
    {
        if (a[i]%10!=0)
        {
            if (b<10-(a[i]%10))
            {
                b=10-a[i]%10;
                c=i;
            }
        }
    }
    int ans=0;
    for (int i=0;i<n;i++)
    {
        if (i==c)
        {
            continue;
        }
        if (a[i]%10==0)
        {
            ans+=a[i];
        }
        else
        {
            ans+=((a[i]/10)+1)*10;
        }
    }
    ans+=a[c];
    cout<<ans;

    return 0;
}
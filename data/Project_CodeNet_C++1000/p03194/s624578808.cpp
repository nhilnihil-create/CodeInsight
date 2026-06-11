#include <bits/stdc++.h>
#define ll long long
#define fort(i,n) for (int i = 1; i <= n; ++i)
#define pi pair<int,int>
#define vi vector<int>
#define pb push_back
#define sz size()
#define er erase
#define fr first
#define sc second
#define rc(x) return cout << x, 0
using namespace std;

ll n,p,d;

ll power(ll a, ll b)
{
    if (b==0ll) return 1ll;
    if (b%2ll==0ll) return power(a,b/2)*power(a,b/2);
    else return a*power(a,b/2)*power(a,b/2);
}

int32_t main()
{
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> p;
    if (n==1) rc(p);
    if (n>log2(p)) rc(1);
    for (ll i = 1ll; i <= p; ++i)
    {
        if (power(i,n)<=p)
        {
            if (p%power(i,n)==0) d=i;
        }
        else break;
    }
    cout << d;
}

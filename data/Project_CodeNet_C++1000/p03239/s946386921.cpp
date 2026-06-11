#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define scl(n) scanf("%lld", &n)
#define pcl(n) printf("%lld\n", n)
#define pcl1(n) printf("%lld ", n)
#define dev(x) cout << #x << " " << x << " ";
#define PTT pair<ll, ll>

map<ll, ll> mp, mp1;
map<ll, ll>::iterator itr;

int main()
{
    ll n, t, c;
    scl(n);
    scl(t);
    vector<PTT> v;
    PTT p;
    for (int i = 0; i < n; i++)
    {
        scl(p.second);
        scl(p.first);
        v.push_back(p);
    }
    sort(v.begin(), v.end());
    
    ll mn = 1e10;
    for (int i = 0; i < n; i++)
    {
        if (v[i].first <= t)
        {
            mn = min(v[i].second, mn);
        }
        else
        {
            break;
        }
    }
    if (mn >=1000000)
    {
        cout << "TLE" << endl;
    }
    else
    {
        cout << mn << endl;
    }

    return 0;
}
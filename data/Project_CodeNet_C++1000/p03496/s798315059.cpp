#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define int ll
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll, ll>
using namespace std;

const ll INF = 1e18+7;
const int maxN = 300005;


main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i=0;i<n;i++)
        cin>>a[i];
    vector<pii> res;
    pii mx={a[0], 0}, mn = {a[0], 0};
    for (int i=1;i<n;i++)
    {
        pii cur = {a[i], i};
        mx = max(cur, mx);
        mn = min(cur, mn);
    }
    if (abs(mn.ff) > abs(mx.ff))
    {
        for (int i=n-2;i>=0;i--)
        {
            while (a[i] > a[i+1])
            {
                a[i] += mn.ff;
                res.pb({mn.ss, i});
                mn = min(mn, {a[i], i});
            }
        }
    }
    else
    {
        for (int i=1;i<n;i++)
        {
            while (a[i]<a[i-1])
            {
                a[i] += mx.ff;
                res.pb({mx.ss, i});
                mx = max(mx, {a[i], i});
            }
        }
    }
    cout<<res.size()<<endl;
    for (int i=0;i<res.size();i++)
        cout<<res[i].ff+1<<' '<<res[i].ss+1<<endl;
}

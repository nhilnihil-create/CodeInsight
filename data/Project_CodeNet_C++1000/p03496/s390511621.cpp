#include<bits/stdc++.h>

#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple

using namespace std;

int a[100];
vector<pair<int,int> > res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int ind = 0;
    int absMax = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(abs(absMax) <= abs(a[i]))
        {
            absMax = a[i];
            ind = i;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        if(ind != i)
        {
            res.pb(mp(ind, i));
            a[i] += absMax;
        }
    }

    if(absMax >= 0)
    {
        int pref = a[1];
        for(int i = 2; i <= n; i++)
        {
            res.pb(mp(i-1, i));
            //a[i] += pref;
            //pref = a[i];
        }
    }
    else
    {
        int pref = a[n];
        for(int i = n-1; i >= 1; i--)
        {
            res.pb(mp(i+1, i));
            //a[i] += pref;
            //pref = a[i];
        }
    }
    cout << res.size() << "\n";
    for(int i = 0; i < res.size(); i++) cout << res[i].fi << " " << res[i].se << "\n";

    return 0;
}

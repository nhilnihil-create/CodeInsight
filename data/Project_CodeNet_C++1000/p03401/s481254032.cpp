#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, n, s) for (int i = (s); i < (n); i++)
#define MOD 1000000007
typedef long long ll;
using namespace std;
using Graph = vector<vector<int>>;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> dist, skip_dist;
    skip_dist.pb(abs(a[1] - 0));
    dist.pb(abs(a[0] - 0));
    ll total = dist[0];
    reps(i, n, 1)
    {
        dist.pb(abs(a[i] - a[i - 1]));
        if (i < n - 1)
        {
            skip_dist.pb(abs(a[i + 1] - a[i - 1]));
        }
        else
        {
            skip_dist.pb(abs(0 - a[i - 1]));
        }
        total += dist[i];
    }
    dist.pb(abs(0 - a[n-1]));
    total+=dist[n];
    rep(i, n)
    {
        cout << total - (dist[i]+dist[i+1]) + skip_dist[i] << endl;
    }

    //system("pause");
    return 0;
}
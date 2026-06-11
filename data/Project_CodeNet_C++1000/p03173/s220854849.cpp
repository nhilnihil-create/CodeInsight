#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<ll, ll>
#define dd pair<double, double>
#define pb(i) push_back(i)
const double PI = 3.14159265359;
const ll inf = 1e18;
const int mod = 1e9+7;
const double eps = 1e-7;
//int dir1[8] = {0, 0, 1, -1, 1, -1, 1, -1};
//int dir2[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dir1[4] = {0, 0, 1, -1};
int dir2[4] = {1, -1, 0, 0};

ll cost(int a, int b);

ll solve(int l, int r);

ll pre[405];

ll dp[405][405];

int main()
{
    int i, j;

    int n;
    cin >> n;
    vector<int> v(n);
    for(i = 0; i < n; i++)
        cin >> v[i];

    pre[0] = v[0];
    for(i = 1; i < n; i++)
        pre[i] = pre[i-1] + v[i];
    
    memset(dp, -1, sizeof(dp));
    cout << solve(0, n-1) << '\n';
}

ll cost(int a, int b)
{
    if(a-1 >= 0)
        return pre[b] - pre[a-1];
    return pre[b];
}

ll solve(int l, int r)
{

    int i, j;

    ll &h = dp[l][r];
    if(l == r)
        return h = 0;

    if(h != -1)
        return h;
    
    h = inf;
    for(i = l; i <= r; i++)
        h = min(h, solve(l, i) + solve(i+1, r) + cost(l, r));

    return h;
}
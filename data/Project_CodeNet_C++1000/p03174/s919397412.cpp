#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define sz(x) ((int)x.size())

const int mod = 1000*1000*1000 + 7;
vector<int> a(1<<21, 0);
vector<int> b[25];
int r[25][25];

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    a[0] = 1;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> r[i][j];
    a[0] = 1;
    for(int i = 1; i < (1<<n); i++)
        b[__builtin_popcount(i)].pb(i);
    for(int i = 1; i <= n; i++)
        for(auto &mask: b[i])
            for(int m = 0; m < n; m++)
                if(((1<<m)&mask) && r[m][i-1])
                    a[mask] += a[mask^(1<<m)], a[mask] %= mod;
    cout << a[(1<<n)-1] << endl;
}
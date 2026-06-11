#include <bits/stdc++.h>
#define int long long 

using namespace std;

const int maxn = 1e5 + 7;

vector<array<int, 3>> edge;
int l;
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen("test.inp", "r")) freopen("test.inp", "r", stdin);
    cin >> l;
    int n = 0, val = 0;
    while((1 << n) - 1 <= l - 1) n++;
    for(int i = 2; i <= n; i++)
    {
        edge.push_back({i - 1, i, (1 << n - i)});
        edge.push_back({i - 1, i, 0});
    }
    val = 0;
    for(int i = 1; i <= n; i++)
    {
        int total = (1 << n - i) - 1;
        if(total + val <= l - 1)
        {
            if(i != 1)
            edge.push_back({1, i, val});
            val += total + 1;
        }
    }
    cout << n << ' ' << edge.size() << '\n';
    for(auto i: edge) cout << i[0] << ' ' << i[1] << ' ' << i[2] << '\n';
}
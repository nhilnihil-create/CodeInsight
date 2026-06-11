#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<ll> a(n);
    vector<P> query(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> query[i].first >> query[i].second;
    
    sort(a.begin(), a.end());
    sort(query.begin(), query.end(), [](P& a, P& b){ return a.second > b.second; });

    int idxa = 0;
    for (int i = 0; i < m; ++i)
    {
        int b = query[i].first;
        int c = query[i].second;
        if (c <= a[idxa]) break;
        bool ok = false;
        for (int k = 0; k < b; ++k)
        {
            a[idxa] = c;
            ++idxa;
            if (idxa >= n || a[idxa] >= c)
            {
                ok = true;
                break;
            }
        }
        if (ok) break;
    }

    ll sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += a[i];
    }
    cout << sum << endl;
    return 0;
}

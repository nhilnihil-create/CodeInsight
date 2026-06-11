#include <iostream>
#include <cstdio>
#include <algorithm>
#define fi first
#define se second
using namespace std;
 
const int N = 100005, M = 100005;
 
int n, m, a[N];
pair<int, int> rep[M];
 
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> rep[i].se >> rep[i].fi;
    sort(a + 1, a + n + 1);
    sort(rep + 1, rep + m + 1, greater<pair<int, int>>());
    for (int i = 1, pt = 1; i <= m && pt <= n; i++)
        while (rep[i].se--)
            if (pt > n || a[pt] >= rep[i].fi)
            {
                pt = n + 1;
                break;
            }
            else
                a[pt++] = rep[i].fi;
    long long su = 0;
    for (int i = 1; i <= n; i++)
        su += a[i];
    cout << su;
}
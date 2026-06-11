#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define l first
#define r second
#define int long long

int n, m;
string s;
pair<char, char> d[500000];

int simulate(int i)
{
    for (int j = 0; j < m; j++)
    {
        if (d[j].l == s[i])
        {
            if (d[j].r == 'R') i++;
            else i--;
        }
        if (i == -1 || i == n) return i;
    }
    return i;
}

signed main()
{
    cin >> n >> m; 
    cin >> s;
    for (int i = 0; i < m; i++) cin >> d[i].l >> d[i].r;
    int l = -1, r = n;
    while (l + 1 < r)
    {
        int mid = (l + r) / 2;
        if (simulate(mid) == -1) l = mid;
        else r = mid;
    }
    int l2 = -1, r2 = n;
    while (l2 + 1 < r2)
    {
        int mid = (l2 + r2) / 2;
        if (simulate(mid) == n) r2 = mid;
        else l2 = mid;
    }
    cout << min(n, max(0LL, r2 - l - 1));
}

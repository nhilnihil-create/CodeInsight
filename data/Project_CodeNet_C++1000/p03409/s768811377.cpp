#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> p(2 * n);
    map<int, bool> isred;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first >> p[i].second;
        isred[p[i].first] = 1;
    }
    for (int i = n; i < 2 * n; i++)
        cin >> p[i].first >> p[i].second;

    sort(p.begin(), p.end());
    set<int> t;
    int ans = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if (isred[p[i].first])
            t.insert(p[i].second);
        else
        {
            int a = -1;
            for (int x : t)
            {
                if (p[i].second > x)
                    a = x;
                else
                    break;
            }
            if (a != -1)
            {
                t.erase(a);
                ans += 1;
            }
        }
    }
    cout << ans << endl;
}

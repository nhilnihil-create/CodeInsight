#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h, w, n;
    cin >> h >> w >> n;
    vector<set<int>> d(w+1);
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        d[b].insert(a);
    }
    int ans = h;

    int now = 2;
    for(int i = 1; i <= w; i++)
    {
        auto titr = d[i].lower_bound(now);
        if(titr != d[i].end())
        {
            ans = min(ans, *titr-1);
        }
        if(i == w) break;
        while(true)
        {
            if(now == h)
            {
                cout << ans << endl;
                return 0;
            }
            auto itr = d[i+1].find(now);
            if(itr != d[i+1].end())
            {
                now++;
                continue;
            }
            else
            {
                now++;
                break;
            }
        }
    }
    cout << ans << endl;
}

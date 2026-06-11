#include <bits/stdc++.h>

using namespace std;

int n, ap[20];

int take(vector<int> v)
{
    int ans = 24;

    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); ++i)
        for(int j=i+1; j<v.size(); ++j)
        {
            int a = v[i], b = v[j];

            ans = min(ans, b-a);
            ans = min(ans, 24-b+a);
        }
    return ans;
}

int main()
{
   // freopen("input", "r", stdin);
    cin.sync_with_stdio(false); cin.tie(0);

    cin >> n;

    int i, j;
    for(i=1; i<=n; ++i)
    {
        int x;
        cin >> x;
        ++ap[x];
    }

    ap[0] ++;

    vector<int> v, w;

    for(i=0; i<=12; ++i)
        if(ap[i] >= 3)
        {
            cout << 0 << '\n';
            exit(0);
        }
        else if(ap[i] == 2)
        {
            v.push_back(i);
            v.push_back(-i);
        }
        else if(ap[i] == 1)
            w.push_back(i);

    int ans = 0;

    for(i=0; i<(1<<(int)w.size()); ++i)
    {
        vector<int> vv = v;

        for(j=0; j<w.size(); ++j)
            if(i & (1<<j)) vv.push_back(w[j]);
                else vv.push_back(-w[j]);

        ans = max(ans, take(vv));
    }

    cout << ans << '\n';

    return 0;
}

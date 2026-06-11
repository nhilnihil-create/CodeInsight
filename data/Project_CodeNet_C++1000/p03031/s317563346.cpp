#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>>v(m);
    vector<int>k(m);
    vector<int>p(m);
    for(int i = 0; i < m; i++)
    {
        cin >> k[i];
        v[i].resize(k[i]);
        for(int j = 0; j < k[i]; j++)
        {
            cin >> v[i][j];
            v[i][j]--;
        }
        sort(v[i].begin(),v[i].end());
    }
    for(int i = 0; i < m; i++)
    {
        cin >> p[i];
    }
    vector<bool>f;
    int result = 0;
    for(int bit = 0; bit <(1<<n); bit++)
    {
        bool val = true;
        f.assign(n,false);
        for(int i = 0; i < n; i++)
        {
            if(bit&(1<<i))
            {
                f[i] = true;
            }
        }
        for(int i = 0; i < m; i++)
        {
            int count = 0;
            for(auto x: v[i])
            {
                if(f[x])
                {
                    count++;
                }
            }
            if(count % 2 != p[i])
            {
                val = false;
                break;
            }
        }
        if(val)
        {
            result++;
        }
    }
    cout << result << endl;
    return 0;
}

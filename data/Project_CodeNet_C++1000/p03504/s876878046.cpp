#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pdd pair<double,double>

int N, C;
vector<pdd> V[40];
vector<double> S;

signed main()
{
    cin >> N >> C;
    rep(i, N)
    {
        double s, t;
        int c;
        cin >> s >> t >> c;
        V[c].push_back({s, t});
    }

    for(int i = 1; i <= C; i++)sort(V[i].begin(), V[i].end());

    for(int i = 1; i <= C; i++)
    {
        for(int j = 0; j < V[i].size(); j++)
        {
            double s = V[i][j].first - 0.5;
            while(j != V[i].size() - 1 && V[i][j].second == V[i][j + 1].first)j++;
            double t = V[i][j].second;
            S.push_back(s);
            S.push_back(t);
        }
    }

    sort(S.begin(), S.end());

    int ans = 0;
    int tmp = 0;
    for(auto e : S)
    {
        //cout << e << endl;
        if(e == (int)e)
        {
            tmp++;
        }
        else
        {
            if(tmp == 0)ans++;
            else tmp--;
        }
    }

    cout << ans << endl;

    return 0;
}

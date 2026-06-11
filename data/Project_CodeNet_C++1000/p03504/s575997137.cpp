#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N, C;
    cin >> N >> C;
    vector<ll> s(N), t(N), c(N);
    ll tMax = 0;
    REP(i, N)
    {
        cin >> s[i] >> t[i] >> c[i];
        c[i]--;
        tMax = max(tMax, t[i]);
    }
    vector<double> sD[C], tD[C];
    priority_queue<double, vector<double>, greater<double>> sDQ[C], tDQ[C];
    REP(i, N)
    {
        sDQ[c[i]].push((double)s[i] - 0.5);
        tDQ[c[i]].push((double)t[i]);
    }
    REP(i, C)
    {
        while(!sDQ[i].empty() && !tDQ[i].empty())
        {
            sD[i].push_back(sDQ[i].top());
            sDQ[i].pop();
            tD[i].push_back(tDQ[i].top());
            tDQ[i].pop();
        }
    }

    map<double, ll> countRecord; 
    for (ll i = 1; i <= 2 * tMax; ++i)
    {
        double now = 0.5 * i;
        countRecord[now] = 0;
        REP(i, C)
        {
            if (sD[i].size() == 0)
            {
                continue;
            }

            auto it = lower_bound(ALL(sD[i]), now);
            if (it == sD[i].end())
            {
                if (now < tD[i][tD[i].size() - 1])
                {
                    countRecord[now]++;
                }
            }
            else
            {
                int index = distance(sD[i].begin(), it);
                if (now == sD[i][index]) 
                {
                    countRecord[now]++;
                }
                else
                {
                    if (index - 1 >= 0 && now < tD[i][index - 1]) 
                    {
                        countRecord[now]++;
                    }
                }
            }
        }
    }

    ll ans = 0;
    REPV(it, countRecord)
    {
        ans = max(ans, it->second);
    }

    cout << ans << endl;
}

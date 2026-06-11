#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int N, M;
    cin >> N >> M;
    vector<int> k(M);
    vector<vector<int>> s(M);
    vector<int> p(M);

    for (int i = 0; i < M; i++)
    {
        cin >> k[i];
        for (int j = 0; j < k[i]; j++)
        {
            int val;
            cin >> val;
            s[i].push_back(val);
        }
    }

    for (int i = 0; i < M; i++)
    {
        cin >> p[i];
    }
    
    vector<int> swStat(N,0);
    ll ans = 0;
    for (int i = 0; i < (1 << N); i++)
    {
        for (int j = 0; j < N; j++)
        {
            swStat[j] = (i >> j) & 1;
        }
        
        bool allOn = true;
        for (int i = 0; i < M; i++)
        {
            int ons = 0;
            for (int j = 0; j < k[i]; j++)
            {
                ons += swStat[s[i][j]-1];
            }
            if(p[i] != (ons % 2)) {
                allOn = false;
                break;
            }
        }

        if(allOn) ans++;
    }
    
    cout << ans << endl;

    return 0;
}

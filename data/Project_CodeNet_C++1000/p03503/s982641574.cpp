#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = INT_MAX / 2;

int main() {
    int N; cin >> N;
    vector<vector<bool>> f(N, vector<bool>(10));
    vector<vector<ll>> p(N, vector<ll>(11));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int F; cin >> F;
            if(F==1) f[i][j] = true;
            else f[i][j] = false;
        }
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= 10; j++)
        {
            cin >> p[i][j];
        }
    }

    ll ans = -INF;
    for (int i = 1; i < (1<<10); i++)
    {
        vector<int> nopen(N, 0);
        for (int j = 0; j < 10; j++)
        {
            if(!((i >> j) & 1)) continue;
            for (int k = 0; k < N; k++)
            {
                if(f[k][j]) nopen[k]++; 
            }
        }
        ll score = 0;
        for (int j = 0; j < N; j++)
        {
            score += p[j][nopen[j]];
        }
        ans = max(ans, score);
    }
    cout << ans << endl;
    
}
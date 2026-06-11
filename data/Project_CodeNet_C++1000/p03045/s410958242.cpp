#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(int num, map<int, set<int>>& mp, vector<bool>& bmp)
{
    if(bmp[num]) return;
    bmp[num] = true;
    for(auto itr = mp[num].begin(); itr != mp[num].end(); itr++)
    {
        dfs(*itr, mp, bmp);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> X(M), Y(M), Z(M);
    map<int, set<int>> mp;
    for(int i=0; i<M; i++)
    {
        cin >> X[i] >> Y[i] >> Z[i];
        X[i]--; Y[i]--;
        mp[X[i]].insert(Y[i]);
        mp[Y[i]].insert(X[i]);
    }

    vector<bool> bmp(N, false);
    int cls = 0;
    for(int i=0; i<M; i++)
    {
        if(bmp[X[i]] && bmp[Y[i]]) continue;
        cls++;
        dfs(X[i], mp, bmp);
    }
    int ans = cls;
    for(int i=0; i<N; i++) if(!bmp[i]) ans++;

    cout << ans << endl;

    return 0;
}

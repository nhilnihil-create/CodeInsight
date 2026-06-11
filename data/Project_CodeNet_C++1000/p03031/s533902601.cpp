#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> K(M);
    vector<vector<int>> S(M);
    for(int i=0; i<M; i++)
    {
        cin >> K[i];
        S[i].resize(K[i]);
        for(int j=0; j<K[i]; j++)
        {
            cin >> S[i][j];
            S[i][j]--;
        }
    }
    vector<int> P(M);
    for(int i=0; i<M; i++) cin >> P[i];

    int ans = 0;
    for(int bit=0; bit < (1<<N); bit++)
    {
        vector<bool> mp(N, false);
        for(int i=0; i<N; i++)
        {
            if(bit & (1<<i))
            {
                mp[i] = true;
            }
        }
        bool ok = true;
        for(int i=0; i<M; i++)
        {
            int cnt = 0;
            for(int j=0; j<K[i]; j++) if(mp[S[i][j]]) cnt++;
            if(cnt%2 != P[i]) ok = false;
        }
        if(ok) ans++;
    }
    cout << ans << endl;

    return 0;
}

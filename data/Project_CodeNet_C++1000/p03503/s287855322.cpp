#include <bits/stdc++.h>
#define H ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ld long double
using namespace std;
const ll  mod = 998244353;

int n;
vector <int> period[10];
ll p[100][11];
bool vis[10][2000];
ll mem[10][2000];

ll dp(int idx, int msk, vector<int> v){
    if (idx >= 10){
        if (msk == 0){
            return LONG_LONG_MIN;
        }
        ll cnt = 0;
        for (int i = 0; i < n; i++){
            cnt += p[i][v[i]];
        }
        return cnt;
    }

    ll &ret = mem[idx][msk];
    if (vis[idx][msk]) return ret;
    vis[idx][msk] = 1;
    ret = dp(idx + 1, msk, v);
    int nmsk = (msk | (1 << idx));
    for (int i = 0; i < period[idx].size(); i++){
        v[period[idx][i]]++;
    }
    return ret = max(ret, dp(idx + 1, nmsk, v));
}

int main()
{
    H

    cin >> n;
    vector<int> v(n, 0);
    int x;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 10; j++){
            cin >> x;
            if (x){
                period[j].push_back(i);
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= 10; j++){
            cin >> p[i][j];
        }
    }
    cout << dp(0, 0, v);
    return 0 ;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M; cin >> N >> M;
    vector<vector<ll>> v(8, vector<ll>(N));
    for (int i = 0; i < N; i++)
    {
        ll x, y, z; cin >> x >> y >> z;
        v[0][i] = x + y + z;
        v[1][i] = x - y + z; 
        v[2][i] = x + y - z; 
        v[3][i] = -x + y + z; 
        v[4][i] = x - y - z; 
        v[5][i] = -x - y + z; 
        v[6][i] = -x + y - z; 
        v[7][i] = -x - y - z; 
    }
    for (int i = 0; i < 8; i++)
    {
        sort(v[i].begin(),v[i].end(), greater<ll>());
    }
    
    ll ans = 0;
    for (int i = 0; i < 8; i++)
    {
        ans = max(ans, accumulate(v[i].begin(),v[i].begin()+M, 0LL));
    }
    cout << ans << endl;
}
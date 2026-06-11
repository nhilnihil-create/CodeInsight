#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 10000000000
using namespace std;
using ll = long long;
int memo[90005];
int main()
{
    int h, w, d;
    cin >> h >> w >> d;
    map<int, pair<int, int>> mp;
    rep(i,h){
        rep(j,w){
            int a;
            cin >> a;
            a--;
            mp[a] = make_pair(i, j);
        }
    }
    int q;
    cin >> q;
    vector<int> L(q), R(q);
    rep(i,q){
        cin >> L[i] >> R[i];
        L[i]--;
        R[i]--;
    }
    ll ans = 0;
    rep(i,h*w-d){
        memo[i + d] = memo[i] + abs(mp[i].first - mp[i + d].first) + abs(mp[i].second - mp[i + d].second);
    }
    rep(i,q){
        cout << memo[R[i]] - memo[L[i]] << endl;
    }

}
        

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <cstring>

using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using PP = pair<ll, pair<ll,ll>>;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

ll n, m, ans;
ll map[50][50];
ll u[50];
P e[50];

int main() {
    cin >> n >> m;
    rep(i,m){
        cin >> e[i].first >> e[i].second;
        e[i].first--;
        e[i].second--;
        map[e[i].first][e[i].second] = 1;
        map[e[i].second][e[i].first] = 1;
    }
    ans = 0;
    rep(i,m){
        map[e[i].first][e[i].second] = 0;
        map[e[i].second][e[i].first] = 0;

        rep(j,n) u[j] = -1;

        rep(j,n-1){
            for(ll k = j+1; k < n; k++){
                if (map[j][k] == 1){
                    if (u[j] == -1 && u[k] == -1){
                        u[j] = j;
                        u[k] = j;
                    }
                    else if (u[j] != -1 && u[k] == -1){
                        u[k] = u[j];
                    }
                    else if (u[j] == -1 && u[k] != -1){
                        u[j] = u[k];
                    }
                    else {
                        ll tmp = u[k];
                        rep(l,n) if (u[l] == tmp) u[l] = u[j];
                    }
                }
            }
        }

        ll f = 0;
        rep(j,n) if (u[j] != u[0]) f = 1;
        if (f) ans++;
        
        map[e[i].first][e[i].second] = 1;
        map[e[i].second][e[i].first] = 1;
    }
    cout << ans << endl;
}
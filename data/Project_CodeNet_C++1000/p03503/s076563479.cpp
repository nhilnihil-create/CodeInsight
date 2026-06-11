#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, 1, 0, -1};

int main(void){
    ll n;
    cin >> n;
    ll f[1000][15], p[1000][15];
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < 10; j++)
            cin >> f[i][j];
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j <= 10; j++)
            cin >> p[i][j];
    ll ans = -1e+11;
    for(ll bit = 0; bit < (1<<10); bit++){
        ll check = 0;
        vector<bool> all(n, false);
        for(ll i = 0; i < n; i++){
            ll count = 0;
            for(ll j = 0; j < 10; j++){
                if((bit>>j) & f[i][j]){
                    count++;
                    all[j] = true;
                }
            }
            check+=p[i][count];
        }
        bool zero = true;
        for(ll i = 0; i < n; i++){
            if(all[i]==true) break;
            if(i==n-1) zero = false;
        }
        if(zero==true)
            ans = max(check, ans);
    }
    cout << ans << endl;
    return 0;
}

#include<bits/stdc++.h>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;

signed main() {
    int n , m;
    cin >> n >> m;
    vector<pair<ll, ll>> store(n);
    rep(i, n){
        ll price, cnt;
        cin >> price >> cnt;
        store[i] = make_pair(price, cnt);
    }

    sort(store.begin(), store.end());

    ll now = 0;
    ll now_money = 0;

    for(ll i = 0; now < m; i++){
        for(ll j = store[i].second; j > 0; j--){
            if(now < m){
                now++;
                now_money += store[i].first;
            }
        }
    }

    cout << now_money << endl;

}
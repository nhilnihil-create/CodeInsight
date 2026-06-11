#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> drinks(n+10);
    rep(i, n) {
        cin >> drinks[i].first >> drinks[i].second;
    }
    sort(drinks.begin(), drinks.end());

    ll cost = 0, bottles = 0;
    ll i = 0;
    while(true) {
        cost += drinks[i].first * drinks[i].second;
        bottles += drinks[i].second;
        if (bottles > m) break;
        i++;       
    }
    ll yobun = bottles - m;
    cost -= drinks[i].first * yobun;
    cout << cost << endl;
    return 0;
}
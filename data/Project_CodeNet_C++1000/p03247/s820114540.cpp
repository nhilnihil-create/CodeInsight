#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll,ll>;

int main() {
    int n; cin >> n;
    vector<P> data(n);
    for (int i = 0; i < n; i++) cin >> data[i].first >> data[i].second;

    int check;
    for (int i = 0; i < n; i++) {
        int comp = ( abs(data[i].first) + abs(data[i].second) ) % 2;
        if ( i == 0 ) check = comp;
        else if ( check != comp ) {
            cout << -1 << endl;
            return 0;
        }
        data[i] = make_pair(data[i].first + data[i].second, data[i].first - data[i].second);
    }

    vector<ll> dist;
    for (int i = 30; i >= 0; i--) dist.push_back(1ll<<i);
    if ( check == 0 ) dist.push_back(1ll);
    cout << (int)dist.size() << endl;
    for (int i = 0; i < (int)dist.size(); i++) cout << dist[i] << (i == (int)dist.size() - 1 ? "\n" : " ");

    for (int i = 0; i < n; i++) {
        bool to_x, to_y;
        ll sum_x = 0, sum_y = 0;
        ll goal_x = data[i].first, goal_y = data[i].second;
        for (int j = 0; j < (int)dist.size(); j++) {
            if ( sum_x < goal_x ) { to_x = 1; sum_x += dist[j]; }
            else { to_x = 0; sum_x -= dist[j]; }
            if ( sum_y < goal_y ) { to_y = 1; sum_y += dist[j]; }
            else { to_y = 0; sum_y -= dist[j]; }
            
            if (to_x && to_y) cout << "R";
            else if (to_x) cout << "U";
            else if (to_y) cout << "D";
            else cout << "L";
        }
        cout << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using pint = pair<int, int>;
using pstring = pair<int, string>;
using Graph = vector<vector<char>>;
const ll d_x[4] = {-1, 1, 0, 0};
const ll d_y[4] = {0, 0, -1, 1};

int main() {
    ll ans;
    ll R, C; cin >> R >> C;
    Graph G(R, vector<char>(C));
    ll black = 0;
    for( ll i = 0; i < R; i++ ) {
        for( ll j = 0; j < C; j++ ) {
            char a; cin >> a;
            G.at(i).at(j) = a;
            if( a == '#' ) black++;
        }
    }

    vector<vector<ll>> dist(R, vector<ll>(C, -1));
    queue<pair<ll,ll>> q;

    dist.at(0).at(0) = 0;
    pair<ll, ll> s;
    s.first = 0; s.second = 0;
    q.push(s);

    while(!q.empty()) {
        pair<ll,ll> p = q.front();
        q.pop();
        // cout << p.first << ' ' << p.second << ' ' << dist.at(p.first).at(p.second) << endl;
        for( ll i = 0; i < 4; i++) {
            ll n_x = p.first + d_x[i], n_y = p.second + d_y[i];
            if( n_x < 0 || n_x >= R || n_y < 0 || n_y >= C ||
                G.at(n_x).at(n_y) == '#' ) continue;
            if( dist.at(n_x).at(n_y) != -1 ) continue;
            dist.at(n_x).at(n_y) = dist.at(p.first).at(p.second) + 1;
            s.first = n_x, s.second = n_y;
            q.push(s);
        }
    }

    if(dist.at(R-1).at(C-1) == -1) cout << -1 << endl;
    else cout << R * C - dist.at(R-1).at(C-1) -1 - black << endl;
    // for( ll i = 0; i < R; i++ ) {
    //     for( ll j = 0; j < C; j++ ) {
    //         cout << dist.at(i).at(j) << ' ';
    //     }
    //     cout << endl;
    // }

    return 0;
}

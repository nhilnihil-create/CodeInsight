#include <bits/stdc++.h>

#define REP(i,n) for(int i = 0; i < n; i++)
#define RREP(i, a, b) for (int i = a; i < (b); i++)
#define FOR(i, n) for (int i = n; i >= 0; i--)
using namespace std;
typedef long long ll;
ll M = 32;

ll L1(pair<ll, ll> x){
    return abs(x.first) + abs(x.second);
}

pair<ll, ll> sub(pair<ll, ll> x, pair<ll, ll> y){
    return make_pair(x.first - y.first, x.second - y.second);
}

void operation(ll* dist, pair<ll, ll> y) {
    char op[M+1];
    op[M] = 0;
    pair<ll, ll> now = y;
    for (ll i = M-1; i >=0; i--) {
        pair<ll, ll> u = make_pair(0, dist[i]);
        pair<ll, ll> d = make_pair(0, -dist[i]);
        pair<ll, ll> l = make_pair(-dist[i], 0);
        pair<ll, ll> r = make_pair(dist[i], 0);

        if (L1(sub(now, u)) < dist[i]) {
            op[i] = 'U';
            now = sub(now, u);
        }
        else if(L1(sub(now, d)) < dist[i]) {
            op[i] = 'D';
            now = sub(now, d);
        }
        else if(L1(sub(now, l)) < dist[i]) {
            op[i] = 'L';
            now = sub(now, l);
        }
        else {
            op[i] = 'R';
            now = sub(now, r);
        }
    }
    cout << op << "\n";
}

int main(){
	ll N;
	ll dist[M];
	cin >> N;
	vector<pair<ll, ll> >coor;
	ll parity = -1;
    REP(i, N){
        ll tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        coor.push_back(make_pair(tmp1,tmp2));
        if (parity == -1){
            parity = abs((tmp1 + tmp2) % 2);
        }
        else {
            if (parity != abs((tmp1 + tmp2) % 2)){
                cout << -1 << "\n";
                return 0;
            }
        }
    }

    REP(i, M) dist[i] = pow(2, i);
    if (parity == 1){
        cout << M << "\n";
        REP(i, M) cout << dist[i] << " ";
        cout << "\n";
        REP(i, N) {
            operation(dist, coor[i]);
        }
    }
    else {
        cout << M+1 << "\n";
        cout << 1 << " ";
        REP(i, M) cout << dist[i] << " ";
        cout << "\n";
        pair<ll, ll> offset = make_pair(0, 1);
        REP(i, N) {
            cout << "U";
            operation(dist, sub(coor[i], offset));
        }
    }
}

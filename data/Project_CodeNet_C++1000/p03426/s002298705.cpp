#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    int h, w, d; cin >> h >> w >> d;
    vector<vector<int>> a(h+1, vector<int>(w+1, -1));
    map<int, P> mp;
    rep(i, h) rep(j, w){
        cin >> a.at(i+1).at(j+1);
        mp[a.at(i+1).at(j+1)] = make_pair(i+1, j+1);
    }

    int q; cin >> q;
    vector<int> l(q), r(q);
    rep(i, q) cin >> l.at(i) >> r.at(i);

    vector<int> d2(h*w+1, 0);
    for(int i=d+1; i<=h*w; i++){
        d2.at(i) = d2.at(i-d) + (ll)abs(mp[i].first - mp[i-d].first) + (ll)abs(mp[i].second - mp[i-d].second); 
    } 

    rep(i, q){
        cout << d2.at(r.at(i)) - d2.at(l.at(i)) << endl;
    }

    return 0;
}

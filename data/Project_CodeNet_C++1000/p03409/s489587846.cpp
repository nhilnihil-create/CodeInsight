#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
using ll = long long ;
using P = pair<ll,ll>;
ll INF = 1000000007;
// ll INF = 9223372036854775807;
// ll INF = 998244353;

bool sorty(P l, P r){
    return l.second>=r.second;
}
int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    ll n;
    cin >> n;
    vector<P> red,blue;
    ll x,y;
    rep(i,n){
        cin >> x >> y;
        red.push_back(make_pair(x,y));
    }
    rep(i,n){
        cin >> x >> y;
        blue.push_back(make_pair(x,y));
    }
    sort(red.begin(), red.end(), sorty);
    sort(blue.begin(), blue.end());
    ll res = 0;
    rep(i,n){
        ll bluey = blue.at(i).second;
        ll bluex = blue.at(i).first;
        rep(j,red.size()){
            ll redy = red.at(j).second;
            ll redx = red.at(j).first;
            if(redy<bluey && redx<bluex){
                res++;
                red.erase(red.begin()+j);
                break;
            }
        }
    }
    cout << res << endl;
}
#include <bits/stdc++.h>
#define repp(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define per(i,n) for (long long i = (n); i >= 0; --i)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    int n,m;
    cin >> n >> m;
    vector<map<ll,ll>> mana(n+1);
    vector<vector<ll>> data(n);
    vector<pair<ll,ll>> raw(m);
    rep(i,m){
        ll p,y;
        cin >> p >> y;
        mana[p][y] = 0;
        data[p-1].push_back(y);
        raw[i] = make_pair(p,y);
    }
    rep(i,n)sort(data[i].begin(),data[i].end());
    rep(i,n){
        rep(j,data[i].size()){
            mana[i+1][data[i][j]] = j+1;
        }
    }
    rep(i,m){
        string p = string(6 - (ll)to_string(raw[i].first).length(),'0') + to_string(raw[i].first);
        string y = string(6 - (ll)to_string(mana[raw[i].first][raw[i].second]).length(),'0') + to_string(mana[raw[i].first][raw[i].second]);
        cout << p << y << "\n";
    }
    return 0;
}
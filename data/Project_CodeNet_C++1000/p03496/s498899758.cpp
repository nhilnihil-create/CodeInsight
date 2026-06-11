#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int main(){
    int n;
    cin >> n;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];

    ll val = 0;
    int pos = 0;
    rep(i, n){
        if(abs(val) < abs(v[i])){
            val = v[i];
            pos = i;
        }
    }

    using P = pair<int, int>;
    vector<P> ans;

    rep(i, n){
        if(val > 0 && v[i] < 0){
            v[i] += val;
            ans.push_back({pos, i});
        }
        if(val < 0 && v[i] > 0){
            v[i] += val;
            ans.push_back({pos, i});
        }
    }

    if(val >= 0){
        rep(i, n-1) ans.push_back({i, i+1});
    }
    else{
        for(int i=n-1; i>=1; i--) ans.push_back({i, i-1});
    }

    cout << ans.size() << endl;
    rep(i, ans.size()) cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
}
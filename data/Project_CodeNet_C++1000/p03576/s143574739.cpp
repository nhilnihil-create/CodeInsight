#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n, k;
vector<ll> x, y;
vector<P> v;

bool check(int x1, int x2, int y1, int y2){
    int cnt = 0;
    rep(i,n){
        if(v[i].first < x[x1] || x[x2] < v[i].first) continue;
        if(v[i].second < y[y1] || y[y2] < v[i].second) continue;
        cnt++;
    }
    return cnt >= k;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
    cin >> n >> k;
    x.resize(n);
    y.resize(n);
    rep(i,n){
        cin >> x[i] >> y[i];
        v.emplace_back(x[i], y[i]);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    ll ans = 1e30;
    for(int x1 = 0; x1 < n; x1++){
        for(int x2 = x1; x2 < n; x2++){
            for(int y1 = 0; y1 < n; y1++){
                for(int y2 = y1; y2 < n; y2++){
                    if(check(x1, x2, y1, y2)){
                        ll cmp = (y[y2] - y[y1]) * (x[x2] - x[x1]);
                        chmin(ans, cmp);
                    }
                }
            }
        }
    }
    cout << ans << endl;
	return 0;
}
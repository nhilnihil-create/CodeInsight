#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

const ll INF = 1LL<<60;

int main(){
    int n; cin >> n;
    vector<vector<int>> f(n, vector<int>(10));
    rep(i,n)rep(j,10) cin >> f[i][j];
    vector<vector<int>> p(n, vector<int>(11));
    rep(i,n)rep(j,11) cin >> p[i][j];
    ll ans = -INF;
    for(int bit = 1; bit < (1 << 10); ++bit){
        vector<int> cnt(n,0);
        for(int i = 0; i < 10; ++i){
            if(bit & (1 << i)){
                for(int j = 0; j < n; ++j){
                    if(f[j][i]) cnt[j]++;
                }
            }
        }
        ll tmp = 0;
        for(int i = 0; i < n; i++){
            tmp += p[i][cnt[i]];
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
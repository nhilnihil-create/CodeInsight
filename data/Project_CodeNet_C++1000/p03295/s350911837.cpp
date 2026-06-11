#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define loop(i, a, n) for(int i = (a); i < (n); i++)
using namespace std;
using ll = int64_t;
using P = pair<int, int>;

int main(){
    int n, m; cin >> n >> m;
    P p[m];
    rep(i, m) cin >> p[i].second >> p[i].first;
    sort(p, p+m);

    int ans = 0;
    int pre_b = -1;
    rep(i, m){
        if(p[i].second > pre_b) {
            pre_b = p[i].first-1;
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
#include <bits/stdc++.h>

#define FOR(i, l, r) for(ll i = l; i < r; i++)
#define rep(i, N) FOR(i, 0, N)

using ll = long long int;
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    int n, m; cin >> n >> m;
    vector<P> RL(m);
    rep(i,m) {
        int a,b;
        cin >> a >> b;
        RL[i] = P(b, a);
    }

    sort(RL.begin(), RL.end());
    int ans = 0;

    int gx = 0;
    rep(i, m){
        if(gx <= RL[i].second) {
            ans++;
            gx = RL[i].first;
        }
    }


    cout << ans << "\n";
    return 0;
}

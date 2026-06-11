#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    ll n, m, Q; cin >> n >> m >> Q;
    vector<ll> l(m+2), r(m+2);
    vector<vector<int>> x(n+5, vector<int>(n+5, 0));
    vector<vector<int>> c(n+5, vector<int>(n+5, 0));
    rep(i,m) {
        cin >> l.at(i+1) >> r.at(i+1);
        x.at(l.at(i+1)).at(r.at(i+1))++;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            c.at(i).at(j) = c.at(i).at(j-1) + x.at(i).at(j);
        }
    }

    rep(i, Q) {
        int p, q;
        cin >> p >> q;
        int sum = 0;
        for(int j=p; j<=q; j++){
            sum += c.at(j).at(q) - c.at(j).at(p-1);
        }
        cout << sum << endl;
    }

    return 0;
}
